#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//2020 
//Sifreleme ve þifre çözme algoritma çalýþmasý - fonksiyon kullanýmý yok
//Batuhan YÝÐÝT
int main() {
	
	int sayi,ascii,i,j,k=0,b=0,m=0,n=0,x,yuzler,onlar,birler,asciSayi[3000][3],dizi[5];
	for(i=0;i<3000;i++){for(j=0;j<3;j++){  asciSayi[i][j]=' ';  }}     //Burada asciSayi nin bütün deðerleri boþluk karakterine atandý. Buna 3.KISIM (Deþifreleme) 'da deðinelecek. 
	char sifrelicumle[5000]="\0";	     //strcat fonksyionuyla beraber kullanýlacaðý için böyle baþlatýldý.
	char k1[5],k2[5],k3[5],k0[5],mat[4],cumle[500],Harf,yanit;

	printf("Baslamak icin 4 adet ve birbirinden farkli karakter giriniz (metniniz bu karakterler ile rastgele sifrelenecektir):\n");  // Kullanýcýdan 4 adet 'karakter' girmesini istiyoruz ve bunlarý 
	gets( k0 );																								// gets fonksiyonu ile alýyoruz. gets() kullanmamýzýn nedeni, ileride kullanýcýnýn 
	gets( k1 );																								// gireceði cümleyi string halinde bir diziye almak için gets kullanacak olmamýz.	
	gets( k2 );																								// ( scanf() ve gets birlikte kullanýlýnca hata veriyor.)
	gets( k3 );

													
		
/* 1.KISIM: ALDIGIMIZ KARAKTERLER ÝLE RASTGELE BÝR DÝZÝ OLUSTURMA*/	
	srand(time(NULL));
	
	for (i=0;i<4;i++)                                        //4 elemanlý bir dizi oluþturacaðýz.Ana amaç bu dizinin her bir elemanýnýn farklý olmasý(ve rastgele). Rastgele bir þifre olusturmak icin, dizi[] matrisine atanan elemanlarýn rastgele olmasýndan yararlanýyoruz.
	{																						  // Örn: dizi[0]=1,dizi[1]=3,dizi[2]=0,dizi[3]=1    veya  dizi[0]=2,dizi[1]=1,dizi[2]=3,dizi[3]=0 gibi 
		dongu:
		dizi[i]=(rand()%(3-n+1))+n;							// [0,3] aralýgýndan rastgele gelen sayý dizi[] ye atanýyor. 			
		if(1<=i)      									  //if, dizi[] elemanýn deðerinin tekrar edip etmediðini kontrol ediyor.(ilk elemaný (i=0) pas geçiyor)
		{
			
			int a;               						 //i nin arkasýndan a deðiþkeni, elemanlar ayný m kontrol ediyor
			for(a=0;a<i;a++)
			{
				if(dizi[i]==dizi[a])
				{					
					goto dongu;      						 //eðer bir deðer ayný çýkarsa deðer atama iþlemleri tekrar gerçekleþiyor
				}						
			}					
		}
	}											
    //mat[] matrisi, kullanýcýdan alýnan karakterleri tutacak. mat[] matrisinin içine, dizi[] deki rastgele sýradaki numaralarý yazýyoruz ki, harflerin mata yazýlmasýný random bir þekilde gerçekleþtirmiþ olalým.  		
	mat[dizi[0]]=k0[0];									
	mat[dizi[1]]=k1[0];
	mat[dizi[2]]=k2[0];
	mat[dizi[3]]=k3[0];
	
    //simdi kullanýcýdan alýnan karakterleri bir matriste rastgele bir þekilde tuttugumuza göre,	bu harfleri, kullanacagýmýz asýl þifre matrisine aktarabiliriz.
	char sifre[10][3]={ {mat[0],mat[0],'\0'},                     
			     		{mat[0],mat[1],'\0'},				// alýnan 4 karakterin, bütün karakterlerin ascii kodlarýný þifreyebilmesi lazým. O zaman bütün rakamlar þifrelenirse, ascii kodlarýný sifrelemek kolay olacak.  
				 		{mat[1],mat[3],'\0'},				// bu yüzden, karakterleri 2 li þekilde grupluyoruz aksi taktirde kullanýcý 10 karakter vermek zorunda kalýrdý.(her rakam için bir karakter)
				 		{mat[1],mat[2],'\0'},				
				 		{mat[2],mat[2],'\0'},				//sifre matrisine yerleþecek olacak mat[i] elemanlarýný , tamamen kafamýza göre sýraladýk. Çünkü mat[] matrisinde de belirli elemanlar yok, random elemanlar var.
				 		{mat[3],mat[3],'\0'},				// (yine de tabi, bazý rakamlarýn þifrelenmiþ hali 2 ayný karakterden oluþmuþ olacak. Mesela: sifre[0] (ilk satir=0.rakamýn þifresi) gibi. )- 
				 		{mat[2],mat[0],'\0'},				// Örnek: mat[0]= '*'  , mat[1] = '?' , mat[3] = '!'       =>   120 sayýsýnýn þifrelenmiþ hali:  *?*!**
				 		{mat[1],mat[1],'\0'},
				 		{mat[2],mat[3],'\0'},
				 		{mat[0],mat[3],'\0'}
						};							
	
/* 2.KISIM: ALINAN CÜMLEYÝ TARAYIP ÞÝFRELÝ HALÝNÝ EKRANA BASTIRMA */
	printf("\n");
	printf("Sifrelenmesini istediginiz metni giriniz (Turkce karakter kullanmayiniz, max 500 karakter):\n");
	gets( cumle );                            // Kullanýcý bir cümle girecek, ve bunu tarayabileceðimiz bir þekilde tek bir stringe almamýz lazým. 
											// Bunun için scanf yetersiz kalýyor çünkü boþlugu gördüðü anda kalan kýsmý almýyor. Bu yüzden gets i kullandýk.					
	
	for(i=0;cumle[i]!='\0';i++)        		//cümle stringinin son elamanýna gelene kadar, bütün elemanlarýnýn (yani karakterlerinin) sayýsý kadar döngü dönecek.
	{
	
	Harf=("%c",cumle[i]);					// Taranan karakter, harf adýndaki bir char deðiþkenine atanýyor.
	 
	ascii=("%d",Harf);                 	 // Sonra bu harfin asci kodu, ascii adýndaki bir int deðiþkenine yazýlýyor   (aslýnda burada taranan karakterin ascii kodu hemen bir int deðiþkenine atanabilirdi. fakat böyle görmek daha kolay geldi)     
	
	
	//Alýnan cümlenin þifrelenmiþ halini de, sonradan deþifre etmek üzere, bir matrise atamamýz lazým. Bunun için strcat fonksyionundan yararlandýk. strcat, matrise sayýlarý yazmamýzý kolaylaþtýrýyor.
	yuzler=ascii/100;					//ilk önce ascii kodunun yüzler basamagýný hesaplýyoruz. Ardýndan 2 basamaklý mý yoksa 3 basamaklý mý kontrol ediyoruz.
	
			if(yuzler==0)       
			{									// eðer 2 basamaklý ise, yuzler basamagýný sifrelicumle[] matýna eklemeden  onlar ve birler basamagýnýn þifrelenmiþ halini matrise ekliyor ve ardýndan sonraki sayýyý okuyabilmemiz için boþluk býrakýyor.
			onlar=ascii/10;                           
			birler=ascii%10;
						
			strcat(sifrelicumle, sifre[onlar]);
			strcat(sifrelicumle, sifre[birler]);	
			strcat(sifrelicumle, " ");
			}
			
			else                              // eðer 3 basamaklý ise, ilk önce yuzleri sonra onlar ve birleri matrise ekliyor, ardýndan sonraki sayýyý okuyabilmemiz için boþluk býrakýyor.
			{
				onlar=(ascii%100)/10;
				birler=(ascii%100)%10;
					
					
			strcat(sifrelicumle, sifre[yuzler]);	
			strcat(sifrelicumle, sifre[onlar]);
			strcat(sifrelicumle, sifre[birler]);
			strcat(sifrelicumle, " ");	
			}
							
															// (onlar ve birleri, if ve else in dýþýnda matrise ekleyebilirdik ama bu þekilde görmek kodlama yaparken daha kolay oldu. Çünkü yanlýþlarý ayýrt edebiliyoruz)
	}		
	
		
		
	printf("\nCumlenizin sifreli hali:\n");
												 //sifrelicumle[]  matrisini ekrana yazdýrýr	
	for(i=0;sifrelicumle[i]!='\0';i++)			 //sifrelicumle[] deki karakter sayýsý kadar dönecek				
	{	printf("%c",sifrelicumle[i]);	}        
	
	printf("\n");
	
	
/* 3.KISIM: SÝFREYÝ DESÝFRE ETME VE EKRANA YAZDIRMA */
	
	while(sifrelicumle[k]!='\0')         //k=0 tanýmlanmýþtý. 0. elemendan baþlayarak þifreli cümle taranýyor. Sonunu gördüðü an döngüden çýkacak. For döngüsü kullanamayýz çünkü taranan karaktere göre, k ya 1 artacak ya da 2.
	{	
		
		
		cikis:	
		for(n=0;n<10;n++)        // bu döngüde sifrelicümleden alýnan karakterin sifre matrisindeki dengi bulanacak. 10 tane sifrelenmiþ rakam var, 10 kez dönecek.
		{
																				// if döngüsünün içindeki önerme sayesinde iki karakter birden okunuyor
			if(sifrelicumle[k]==sifre[n][0] && sifrelicumle[k+1]==sifre[n][1])  //eðer sifrelicümleden alýnan karakter, sifre[] nin n. satýrýnda ilk karaktere eþit ve karakterden bir sonraki karakter, sifre[] nin n.satýrýndaki 2. karaktere eþitse (n. satýr, n rakamýný temsil edecek)
			{																	// bir rakam 2 karaktere karþýlýk gelecek, o yüzden bu þekilde tarýyor.   Örnek: sifre[1]={mat[0],mat[1],'\0'}, mat[0]=* mat[1]=? ;  1. rakamýn þifresi= *?  gibi...   , 120: *?*!**  
				asciSayi[b][m]=n;			       		//asciSayi dizisi, int bir dizi, sifrelerin karþýlýk geldiði sayýlarý tutacak (yani asci kodlarýný)
				m++;									//b=0 ve m=0 ile baþlyor, n = þifreyle eþleþen rakam. örnek: asciSayi[0][0] = 1, (örnek: sifre[0]={*,*,'\0'} ve  okunan 2 karakter * * ise, ascisayi[0][1]=0 )
				//printf("%d",n);						// her rakamý eþlediðinde m yi 1 arttýrýyor ki, sonraki okumada ayný b satýrýnýn bir sonraki sutununa alacaðý diðer rakamý yazsýn. (3 sutun var, max 3 basamaklý sayý olabilir)
			}											//NOT:(2 basamaklý sayýlarda, 3. sutun boþ kalýyor. Örnek:asci kodu 93 gelmeliyse, 930 geliyor. Bunu düzeltmek için ilerde baþka bir for döngüsü kullanýldý.)
		
		}
			if(sifrelicumle[k]==' ')			// Sifredeki karakterleri tarayýp boþluða denk gelirse eðer		
			{
				
				m=0;								// Sutun numarasýný 0lýyor. Çünkü sonraki gelen sifre karakterlerinin rakamlarýný ayrý bir satýra yazacak ve tekrar 0 dan yazacak. (Örnek asciSayi[0]=152 , asciSayi[1]=baþka bir sayý olmasý için,  asciSayi[1][m] diye tarayacak, m nin sýfýrlanmasý lazým.)
				b=b+1;							//Satir sayisini bir arttýr. (Sonraki ascii sayisini alacak)
			    //printf(" ");
				k=k+1;					//Ve sifrelicumle[k] boþluða denk geldiyse, taramak için k yý 1 arttýrmasýný söylüyoruz. Çünkü boþluktan sonra hemen bir adet þifre karakteri geliyor.Fakat boþluðu görmediyse k=k+2 olmalý.
				goto cikis;			// k yý 1 kez arttýrdýk. burdan sonra hemen baþa dönmesi lazým. yoksa k yý 2 daha arttýrýr.    
									// cikis: kodunu while ýn içine de koyabiliriz dýþýna da. Sonuçta hiçbir þey okunmadýðý için döngüden çýkacak.
			}
		
		
		k=k+2;							// Þifre karakterleri her rakama 2 adet düþtüðü için, sonraki taramaya 2 karakter sonradan baþlamalý.		
	}
	
	//Duzeltici
	for(i=0;i<b;i++)				//en son b deðiþkeni hangi sayý deðerini tutuyorsa, bu deðer bize asciSayisinin satir sayýsýný, yani kaç tane "karakterlere dönüþtürülmesi gereken" ascii kod u olduðunun bilgisini bize veriyor. b kez taranmalý.
	{	
			
			if(asciSayi[i][2]==' ')    // eðer asci sayýsýnýn son deðeri boþ ise ( asciSayi matrisini tanýmlarken her karaktere (' ') boþluk atanmýþtý. ). Yani sayý 2 basamaklý ({rakam,rakam,' '} ise if in içine girecek.
			{
														// Örnek: asciSayi[i]={9,3,' '}   = asciSayi[i]={0,9,3}   olmasý lazým
				asciSayi[i][2]=asciSayi[i][1];          // 2. sutuna 1.sutunun deðerini yaz      Örnek: asciSayi[i]={9,3,3}
				asciSayi[i][1]=asciSayi[i][0];          // 1. sutuna  0. sutunun deðerini yaz    Örnek: asciSayi[i]={9,9,3}
				asciSayi[i][0]=0;						//0. sutuna 0 yaz	                     Örnek: asciSayi[i]={0,9,3}
				
				
			}
	}
	
		
	printf("\n");
	printf("Desifre edilmis metin:\n");            
	
	for(i=0;i<b;i++)        //b= sutun sayýsý
	{				
			sayi=((asciSayi[i][0])*100)+((asciSayi[i][1])*10)+ ((asciSayi[i][2])*1);       //burada teker teker her satýrýn karþýlýk geldiði basamak deðerlerini hesaplayýp bir int deðiþkeni olan 'sayi' ya atýyor ve sayý yý char halinde bastýrýyor.
			printf("%c",sayi);		                                                       //böylece karakteri elde etmiþ oluyoruz.
	}
	
	
	return 0;
}
