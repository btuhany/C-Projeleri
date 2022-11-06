#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int sifreMat[9][9];     //Text dosyasýna kaydedilecek matris

int dizi[82]; 			/*	Rastgele numaralarýn geleceði ilk matris. Sonradan bu dizi, sifreMat matrisinin elemanlarýyla eþleþtirilecek. 
							2 aþamada yapýlmasýnýn sebebi,rastgele gelen sayilarin terkar etmesini önlemek. Satir matriste kolayca önlenebiliyor.(çünkü tek boyutta taranýyor)
							(9*9=81 elemanlý olabilir en fazla)
                    	*/
                    	
void randomDizi()    	// Random sayilari üreten ve dizi[] 'ye eþleyen fonksiyon
{	
	int i,n,m,a;
	n=0;                     //Buradaki n ve m, random sayilarýn geleceði sayý aralýðýný oluþturuyor. m=122 çünkü, ascii kodlarý küçük harflerin 122de bitiyor. Sonrasýna bakmaya gerek yok.
	m=122;
	srand(time(NULL));        //Rand fonksiyonu için gerekli.
	
	for (i=0;i<54;i++)     //54 adet karakter ile bir þifre oluþturacaðýz. Her dizi[] elemanýna bir karakter düþecek. o zaman for döngüsünün 54 kez dönmesi lazým
	
	{
		dongu:
		dizi[i]=(rand()%(m-n+1))+n;			//dizi[i] ye rastgele bir sayý gelir.       
		
										 // Eðer dizi[] elemanýnýn deðeri ASCII tablosunda 'istediðimiz karakterlerin' deðerinden deðilse while döngüsüne giriyor	
		                                 // while döngüsü  dizi[i] ye atanacak sayý kümesini belirlemeyi saðlýyor.		                                 
										 //	ASCII 32=boþluk,46=nokta,[65-90]=Büyük Harfler,[97-122]=Küçük Harfler
		while( dizi[i] !=32 && dizi[i] !=46 && !(65<=dizi[i] && dizi[i]<=90) && !(97<=dizi[i] && dizi[i]<=122) )
		{
			dizi[i]=(rand()%(m-n+1))+n;      //dizi[i]ye istedigimiz karakterlerin asciikodu gelene kadar. while döngüsü dönecek. 
											//while dönügüsü çýktýðý anda demektir ki: istediðimiz bir karakter geldi.
		}
			
		if(1<=i)       //Bu kýsým, dizi[i] elemanýn deðerinin tekrar edip etmediðini kontrol ediyor.(ilk elemaný (i=0) pas geçiyor)
		{
			
			                
			for(a=0;a<i;a++)		//a=0, dan baþlayan a deðiþkeni, i nin arkasýndan gelerek dizi[] nin   o andaki dizi[i] ye kadar gelen tüm elemanlarýný ayný mý diye kontrol edecek
			{						//Ör: dizi[2]=5 ise, dizi[0] ve dizi[1] i kontrol etmesi yeterli. Bu yüzden a < i.
			
			
				if(dizi[i]==dizi[a])		// Eðer son atanan eleman, önceki atanan elemanlarýn biriyle ayný ise, if in içine gir. 
				{ 
					
					goto dongu;        // Ve döngüye git.  Böylece tüm yapýlanlar tekrarlanacak.
				}
										// Eðer ayný eleman yoksa,  döngüsü i++ yaparak çalýþacak ve böylece dizi[] 54 elemanlý, birbirinden farklý "istedigimiz" karakterler ile dolana dek devam edecek.	
			}
					
		}
			
	}
	
}


int main() 
{
		
	char dosyaAdi[20];           //Kullanýcýnýn adlandýracaðý dosya.txt
	int i,j,satir,sutun;	
	int sayac=0;                //dizi[] yi sifreMat[][] a yazarken kullanacagýmýz index
	
	printf("Matrisin yazilacagi dosya ismini uzantisi ile birlikte veriniz\n");  
	scanf("%s",&dosyaAdi);														//alýnan dosya ismini, dosyaAdi deðiþkenine ata
	satir=9;														//	printf("Matrisin sutun ve satir sayisini ayni sira ile veriniz\n");			
	sutun=9;												//	scanf("%d%d",&satir,&sutun);										// alýnan sutun ve satir numaralarýný satir ve sutun deðiþkenlerine ata
		
	randomDizi();                //ilk baþta yazýlan fonksiyon çalýþýp rastgele sayilar ile dizi[] yi oluþturuyor.
	
	/*
										printf("\n");
										for(i=0;i<54;i++){ printf("%c ",dizi[i]);   */			//-------> program çalýþýyor mu diye kontrol etmemizi kolaylaþtýran kodlar. dizi matrisini yazdýyýor
						
	
	for(i=0;i<satir;i++)          //dizi[]den alýnan sayýlar sifreMat[][]a yerleþtiriliyor
	{
		for(j=0;j<sutun;j++)
		{
			sifreMat[i][j]=dizi[sayac];
			
			sayac=sayac+1;                   //sayac 0 dan baþlýyor, dizi nin içindekiler sýrayla 2 boyutlu asýl sifrematrisimize yazýlýyor
			
			if(sayac>53)        //dizinin [0,54) tane elemaný olacak. 54ten sonrakileri ascii kodu 0 olan null a eþitlemesi için if döngüsü kullanýldý.
			{
				dizi[sayac]=0;
				
			}			
		}
				
	}  
	/*									printf("\n\n");
										for(i=0;i<satir;i++)          
										{
										for(j=0;j<sutun;j++) {
						
										printf("%c ",sifreMat[i][j]);          // --------> sifre matrisini yazdýran kod. Kontrol amaçlý iþe yarýyor.
			
										}
	
											printf("\n"); }   */
	
	
	FILE *dosyaAdres;										//2 boyutlu bir matriste, istedigimiz karakterler random bir þekilde yer aldýðýna göre, þimdi bu matrisi bir text dosyasýna yazabiliriz.
	dosyaAdres = fopen(dosyaAdi,"w");     					//yazma amaçlý, (kullanýcýgýn verdiði ad dosyaAdi'nda tutuluyor) dosyayý aç.(dosya olmadýðý için olusturacak)
	
	fprintf(dosyaAdres,"%d %d",satir,sutun);				//ilk olarak text dosyasýna satir ve sutun sayýsý yazdýrýlýyor (ki ilerde dosya okunurken sutun ve satir sayýsýnýn bilgisi alýnabilsin)
	for(i=0;i<satir;i++)       //kullanýcýdan alýnan isimdeki text dosyasýna, matrisin yazýlma iþlemi
	{
		for(j=0;j<sutun;j++)
		{
			
			fprintf(dosyaAdres,"%c",sifreMat[i][j]);  //charla yazýlýyor ki ascii karakterleri, kod deðil de karakter þeklinde gelsin
			
		}
	
		
	}
	
	fclose(dosyaAdres);      //dosyayý kapat
	
	
	printf("Sifre matrisi dosyasi olusturuldu..");

	
	
	
	return 0;
}
