#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//2020 
//Sifreleme ve �ifre ��zme algoritma �al��mas� - fonksiyon kullan�m� yok
//Batuhan Y���T
int main() {
	
	int sayi,ascii,i,j,k=0,b=0,m=0,n=0,x,yuzler,onlar,birler,asciSayi[3000][3],dizi[5];
	for(i=0;i<3000;i++){for(j=0;j<3;j++){  asciSayi[i][j]=' ';  }}     //Burada asciSayi nin b�t�n de�erleri bo�luk karakterine atand�. Buna 3.KISIM (De�ifreleme) 'da de�inelecek. 
	char sifrelicumle[5000]="\0";	     //strcat fonksyionuyla beraber kullan�laca�� i�in b�yle ba�lat�ld�.
	char k1[5],k2[5],k3[5],k0[5],mat[4],cumle[500],Harf,yanit;

	printf("Baslamak icin 4 adet ve birbirinden farkli karakter giriniz (metniniz bu karakterler ile rastgele sifrelenecektir):\n");  // Kullan�c�dan 4 adet 'karakter' girmesini istiyoruz ve bunlar� 
	gets( k0 );																								// gets fonksiyonu ile al�yoruz. gets() kullanmam�z�n nedeni, ileride kullan�c�n�n 
	gets( k1 );																								// girece�i c�mleyi string halinde bir diziye almak i�in gets kullanacak olmam�z.	
	gets( k2 );																								// ( scanf() ve gets birlikte kullan�l�nca hata veriyor.)
	gets( k3 );

													
		
/* 1.KISIM: ALDIGIMIZ KARAKTERLER �LE RASTGELE B�R D�Z� OLUSTURMA*/	
	srand(time(NULL));
	
	for (i=0;i<4;i++)                                        //4 elemanl� bir dizi olu�turaca��z.Ana ama� bu dizinin her bir eleman�n�n farkl� olmas�(ve rastgele). Rastgele bir �ifre olusturmak icin, dizi[] matrisine atanan elemanlar�n rastgele olmas�ndan yararlan�yoruz.
	{																						  // �rn: dizi[0]=1,dizi[1]=3,dizi[2]=0,dizi[3]=1    veya  dizi[0]=2,dizi[1]=1,dizi[2]=3,dizi[3]=0 gibi 
		dongu:
		dizi[i]=(rand()%(3-n+1))+n;							// [0,3] aral�g�ndan rastgele gelen say� dizi[] ye atan�yor. 			
		if(1<=i)      									  //if, dizi[] eleman�n de�erinin tekrar edip etmedi�ini kontrol ediyor.(ilk eleman� (i=0) pas ge�iyor)
		{
			
			int a;               						 //i nin arkas�ndan a de�i�keni, elemanlar ayn� m kontrol ediyor
			for(a=0;a<i;a++)
			{
				if(dizi[i]==dizi[a])
				{					
					goto dongu;      						 //e�er bir de�er ayn� ��karsa de�er atama i�lemleri tekrar ger�ekle�iyor
				}						
			}					
		}
	}											
    //mat[] matrisi, kullan�c�dan al�nan karakterleri tutacak. mat[] matrisinin i�ine, dizi[] deki rastgele s�radaki numaralar� yaz�yoruz ki, harflerin mata yaz�lmas�n� random bir �ekilde ger�ekle�tirmi� olal�m.  		
	mat[dizi[0]]=k0[0];									
	mat[dizi[1]]=k1[0];
	mat[dizi[2]]=k2[0];
	mat[dizi[3]]=k3[0];
	
    //simdi kullan�c�dan al�nan karakterleri bir matriste rastgele bir �ekilde tuttugumuza g�re,	bu harfleri, kullanacag�m�z as�l �ifre matrisine aktarabiliriz.
	char sifre[10][3]={ {mat[0],mat[0],'\0'},                     
			     		{mat[0],mat[1],'\0'},				// al�nan 4 karakterin, b�t�n karakterlerin ascii kodlar�n� �ifreyebilmesi laz�m. O zaman b�t�n rakamlar �ifrelenirse, ascii kodlar�n� sifrelemek kolay olacak.  
				 		{mat[1],mat[3],'\0'},				// bu y�zden, karakterleri 2 li �ekilde grupluyoruz aksi taktirde kullan�c� 10 karakter vermek zorunda kal�rd�.(her rakam i�in bir karakter)
				 		{mat[1],mat[2],'\0'},				
				 		{mat[2],mat[2],'\0'},				//sifre matrisine yerle�ecek olacak mat[i] elemanlar�n� , tamamen kafam�za g�re s�ralad�k. ��nk� mat[] matrisinde de belirli elemanlar yok, random elemanlar var.
				 		{mat[3],mat[3],'\0'},				// (yine de tabi, baz� rakamlar�n �ifrelenmi� hali 2 ayn� karakterden olu�mu� olacak. Mesela: sifre[0] (ilk satir=0.rakam�n �ifresi) gibi. )- 
				 		{mat[2],mat[0],'\0'},				// �rnek: mat[0]= '*'  , mat[1] = '?' , mat[3] = '!'       =>   120 say�s�n�n �ifrelenmi� hali:  *?*!**
				 		{mat[1],mat[1],'\0'},
				 		{mat[2],mat[3],'\0'},
				 		{mat[0],mat[3],'\0'}
						};							
	
/* 2.KISIM: ALINAN C�MLEY� TARAYIP ��FREL� HAL�N� EKRANA BASTIRMA */
	printf("\n");
	printf("Sifrelenmesini istediginiz metni giriniz (Turkce karakter kullanmayiniz, max 500 karakter):\n");
	gets( cumle );                            // Kullan�c� bir c�mle girecek, ve bunu tarayabilece�imiz bir �ekilde tek bir stringe almam�z laz�m. 
											// Bunun i�in scanf yetersiz kal�yor ��nk� bo�lugu g�rd��� anda kalan k�sm� alm�yor. Bu y�zden gets i kulland�k.					
	
	for(i=0;cumle[i]!='\0';i++)        		//c�mle stringinin son elaman�na gelene kadar, b�t�n elemanlar�n�n (yani karakterlerinin) say�s� kadar d�ng� d�necek.
	{
	
	Harf=("%c",cumle[i]);					// Taranan karakter, harf ad�ndaki bir char de�i�kenine atan�yor.
	 
	ascii=("%d",Harf);                 	 // Sonra bu harfin asci kodu, ascii ad�ndaki bir int de�i�kenine yaz�l�yor   (asl�nda burada taranan karakterin ascii kodu hemen bir int de�i�kenine atanabilirdi. fakat b�yle g�rmek daha kolay geldi)     
	
	
	//Al�nan c�mlenin �ifrelenmi� halini de, sonradan de�ifre etmek �zere, bir matrise atamam�z laz�m. Bunun i�in strcat fonksyionundan yararland�k. strcat, matrise say�lar� yazmam�z� kolayla�t�r�yor.
	yuzler=ascii/100;					//ilk �nce ascii kodunun y�zler basamag�n� hesapl�yoruz. Ard�ndan 2 basamakl� m� yoksa 3 basamakl� m� kontrol ediyoruz.
	
			if(yuzler==0)       
			{									// e�er 2 basamakl� ise, yuzler basamag�n� sifrelicumle[] mat�na eklemeden  onlar ve birler basamag�n�n �ifrelenmi� halini matrise ekliyor ve ard�ndan sonraki say�y� okuyabilmemiz i�in bo�luk b�rak�yor.
			onlar=ascii/10;                           
			birler=ascii%10;
						
			strcat(sifrelicumle, sifre[onlar]);
			strcat(sifrelicumle, sifre[birler]);	
			strcat(sifrelicumle, " ");
			}
			
			else                              // e�er 3 basamakl� ise, ilk �nce yuzleri sonra onlar ve birleri matrise ekliyor, ard�ndan sonraki say�y� okuyabilmemiz i�in bo�luk b�rak�yor.
			{
				onlar=(ascii%100)/10;
				birler=(ascii%100)%10;
					
					
			strcat(sifrelicumle, sifre[yuzler]);	
			strcat(sifrelicumle, sifre[onlar]);
			strcat(sifrelicumle, sifre[birler]);
			strcat(sifrelicumle, " ");	
			}
							
															// (onlar ve birleri, if ve else in d���nda matrise ekleyebilirdik ama bu �ekilde g�rmek kodlama yaparken daha kolay oldu. ��nk� yanl��lar� ay�rt edebiliyoruz)
	}		
	
		
		
	printf("\nCumlenizin sifreli hali:\n");
												 //sifrelicumle[]  matrisini ekrana yazd�r�r	
	for(i=0;sifrelicumle[i]!='\0';i++)			 //sifrelicumle[] deki karakter say�s� kadar d�necek				
	{	printf("%c",sifrelicumle[i]);	}        
	
	printf("\n");
	
	
/* 3.KISIM: S�FREY� DES�FRE ETME VE EKRANA YAZDIRMA */
	
	while(sifrelicumle[k]!='\0')         //k=0 tan�mlanm��t�. 0. elemendan ba�layarak �ifreli c�mle taran�yor. Sonunu g�rd��� an d�ng�den ��kacak. For d�ng�s� kullanamay�z ��nk� taranan karaktere g�re, k ya 1 artacak ya da 2.
	{	
		
		
		cikis:	
		for(n=0;n<10;n++)        // bu d�ng�de sifrelic�mleden al�nan karakterin sifre matrisindeki dengi bulanacak. 10 tane sifrelenmi� rakam var, 10 kez d�necek.
		{
																				// if d�ng�s�n�n i�indeki �nerme sayesinde iki karakter birden okunuyor
			if(sifrelicumle[k]==sifre[n][0] && sifrelicumle[k+1]==sifre[n][1])  //e�er sifrelic�mleden al�nan karakter, sifre[] nin n. sat�r�nda ilk karaktere e�it ve karakterden bir sonraki karakter, sifre[] nin n.sat�r�ndaki 2. karaktere e�itse (n. sat�r, n rakam�n� temsil edecek)
			{																	// bir rakam 2 karaktere kar��l�k gelecek, o y�zden bu �ekilde tar�yor.   �rnek: sifre[1]={mat[0],mat[1],'\0'}, mat[0]=* mat[1]=? ;  1. rakam�n �ifresi= *?  gibi...   , 120: *?*!**  
				asciSayi[b][m]=n;			       		//asciSayi dizisi, int bir dizi, sifrelerin kar��l�k geldi�i say�lar� tutacak (yani asci kodlar�n�)
				m++;									//b=0 ve m=0 ile ba�lyor, n = �ifreyle e�le�en rakam. �rnek: asciSayi[0][0] = 1, (�rnek: sifre[0]={*,*,'\0'} ve  okunan 2 karakter * * ise, ascisayi[0][1]=0 )
				//printf("%d",n);						// her rakam� e�ledi�inde m yi 1 artt�r�yor ki, sonraki okumada ayn� b sat�r�n�n bir sonraki sutununa alaca�� di�er rakam� yazs�n. (3 sutun var, max 3 basamakl� say� olabilir)
			}											//NOT:(2 basamakl� say�larda, 3. sutun bo� kal�yor. �rnek:asci kodu 93 gelmeliyse, 930 geliyor. Bunu d�zeltmek i�in ilerde ba�ka bir for d�ng�s� kullan�ld�.)
		
		}
			if(sifrelicumle[k]==' ')			// Sifredeki karakterleri taray�p bo�lu�a denk gelirse e�er		
			{
				
				m=0;								// Sutun numaras�n� 0l�yor. ��nk� sonraki gelen sifre karakterlerinin rakamlar�n� ayr� bir sat�ra yazacak ve tekrar 0 dan yazacak. (�rnek asciSayi[0]=152 , asciSayi[1]=ba�ka bir say� olmas� i�in,  asciSayi[1][m] diye tarayacak, m nin s�f�rlanmas� laz�m.)
				b=b+1;							//Satir sayisini bir artt�r. (Sonraki ascii sayisini alacak)
			    //printf(" ");
				k=k+1;					//Ve sifrelicumle[k] bo�lu�a denk geldiyse, taramak i�in k y� 1 artt�rmas�n� s�yl�yoruz. ��nk� bo�luktan sonra hemen bir adet �ifre karakteri geliyor.Fakat bo�lu�u g�rmediyse k=k+2 olmal�.
				goto cikis;			// k y� 1 kez artt�rd�k. burdan sonra hemen ba�a d�nmesi laz�m. yoksa k y� 2 daha artt�r�r.    
									// cikis: kodunu while �n i�ine de koyabiliriz d���na da. Sonu�ta hi�bir �ey okunmad��� i�in d�ng�den ��kacak.
			}
		
		
		k=k+2;							// �ifre karakterleri her rakama 2 adet d��t��� i�in, sonraki taramaya 2 karakter sonradan ba�lamal�.		
	}
	
	//Duzeltici
	for(i=0;i<b;i++)				//en son b de�i�keni hangi say� de�erini tutuyorsa, bu de�er bize asciSayisinin satir say�s�n�, yani ka� tane "karakterlere d�n��t�r�lmesi gereken" ascii kod u oldu�unun bilgisini bize veriyor. b kez taranmal�.
	{	
			
			if(asciSayi[i][2]==' ')    // e�er asci say�s�n�n son de�eri bo� ise ( asciSayi matrisini tan�mlarken her karaktere (' ') bo�luk atanm��t�. ). Yani say� 2 basamakl� ({rakam,rakam,' '} ise if in i�ine girecek.
			{
														// �rnek: asciSayi[i]={9,3,' '}   = asciSayi[i]={0,9,3}   olmas� laz�m
				asciSayi[i][2]=asciSayi[i][1];          // 2. sutuna 1.sutunun de�erini yaz      �rnek: asciSayi[i]={9,3,3}
				asciSayi[i][1]=asciSayi[i][0];          // 1. sutuna  0. sutunun de�erini yaz    �rnek: asciSayi[i]={9,9,3}
				asciSayi[i][0]=0;						//0. sutuna 0 yaz	                     �rnek: asciSayi[i]={0,9,3}
				
				
			}
	}
	
		
	printf("\n");
	printf("Desifre edilmis metin:\n");            
	
	for(i=0;i<b;i++)        //b= sutun say�s�
	{				
			sayi=((asciSayi[i][0])*100)+((asciSayi[i][1])*10)+ ((asciSayi[i][2])*1);       //burada teker teker her sat�r�n kar��l�k geldi�i basamak de�erlerini hesaplay�p bir int de�i�keni olan 'sayi' ya at�yor ve say� y� char halinde bast�r�yor.
			printf("%c",sayi);		                                                       //b�ylece karakteri elde etmi� oluyoruz.
	}
	
	
	return 0;
}
