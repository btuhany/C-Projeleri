#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int sifreMat[9][9];     //Text dosyas�na kaydedilecek matris

int dizi[82]; 			/*	Rastgele numaralar�n gelece�i ilk matris. Sonradan bu dizi, sifreMat matrisinin elemanlar�yla e�le�tirilecek. 
							2 a�amada yap�lmas�n�n sebebi,rastgele gelen sayilarin terkar etmesini �nlemek. Satir matriste kolayca �nlenebiliyor.(��nk� tek boyutta taran�yor)
							(9*9=81 elemanl� olabilir en fazla)
                    	*/
                    	
void randomDizi()    	// Random sayilari �reten ve dizi[] 'ye e�leyen fonksiyon
{	
	int i,n,m,a;
	n=0;                     //Buradaki n ve m, random sayilar�n gelece�i say� aral���n� olu�turuyor. m=122 ��nk�, ascii kodlar� k���k harflerin 122de bitiyor. Sonras�na bakmaya gerek yok.
	m=122;
	srand(time(NULL));        //Rand fonksiyonu i�in gerekli.
	
	for (i=0;i<54;i++)     //54 adet karakter ile bir �ifre olu�turaca��z. Her dizi[] eleman�na bir karakter d��ecek. o zaman for d�ng�s�n�n 54 kez d�nmesi laz�m
	
	{
		dongu:
		dizi[i]=(rand()%(m-n+1))+n;			//dizi[i] ye rastgele bir say� gelir.       
		
										 // E�er dizi[] eleman�n�n de�eri ASCII tablosunda 'istedi�imiz karakterlerin' de�erinden de�ilse while d�ng�s�ne giriyor	
		                                 // while d�ng�s�  dizi[i] ye atanacak say� k�mesini belirlemeyi sa�l�yor.		                                 
										 //	ASCII 32=bo�luk,46=nokta,[65-90]=B�y�k Harfler,[97-122]=K���k Harfler
		while( dizi[i] !=32 && dizi[i] !=46 && !(65<=dizi[i] && dizi[i]<=90) && !(97<=dizi[i] && dizi[i]<=122) )
		{
			dizi[i]=(rand()%(m-n+1))+n;      //dizi[i]ye istedigimiz karakterlerin asciikodu gelene kadar. while d�ng�s� d�necek. 
											//while d�n�g�s� ��kt��� anda demektir ki: istedi�imiz bir karakter geldi.
		}
			
		if(1<=i)       //Bu k�s�m, dizi[i] eleman�n de�erinin tekrar edip etmedi�ini kontrol ediyor.(ilk eleman� (i=0) pas ge�iyor)
		{
			
			                
			for(a=0;a<i;a++)		//a=0, dan ba�layan a de�i�keni, i nin arkas�ndan gelerek dizi[] nin   o andaki dizi[i] ye kadar gelen t�m elemanlar�n� ayn� m� diye kontrol edecek
			{						//�r: dizi[2]=5 ise, dizi[0] ve dizi[1] i kontrol etmesi yeterli. Bu y�zden a < i.
			
			
				if(dizi[i]==dizi[a])		// E�er son atanan eleman, �nceki atanan elemanlar�n biriyle ayn� ise, if in i�ine gir. 
				{ 
					
					goto dongu;        // Ve d�ng�ye git.  B�ylece t�m yap�lanlar tekrarlanacak.
				}
										// E�er ayn� eleman yoksa,  d�ng�s� i++ yaparak �al��acak ve b�ylece dizi[] 54 elemanl�, birbirinden farkl� "istedigimiz" karakterler ile dolana dek devam edecek.	
			}
					
		}
			
	}
	
}


int main() 
{
		
	char dosyaAdi[20];           //Kullan�c�n�n adland�raca�� dosya.txt
	int i,j,satir,sutun;	
	int sayac=0;                //dizi[] yi sifreMat[][] a yazarken kullanacag�m�z index
	
	printf("Matrisin yazilacagi dosya ismini uzantisi ile birlikte veriniz\n");  
	scanf("%s",&dosyaAdi);														//al�nan dosya ismini, dosyaAdi de�i�kenine ata
	satir=9;														//	printf("Matrisin sutun ve satir sayisini ayni sira ile veriniz\n");			
	sutun=9;												//	scanf("%d%d",&satir,&sutun);										// al�nan sutun ve satir numaralar�n� satir ve sutun de�i�kenlerine ata
		
	randomDizi();                //ilk ba�ta yaz�lan fonksiyon �al���p rastgele sayilar ile dizi[] yi olu�turuyor.
	
	/*
										printf("\n");
										for(i=0;i<54;i++){ printf("%c ",dizi[i]);   */			//-------> program �al���yor mu diye kontrol etmemizi kolayla�t�ran kodlar. dizi matrisini yazd�y�or
						
	
	for(i=0;i<satir;i++)          //dizi[]den al�nan say�lar sifreMat[][]a yerle�tiriliyor
	{
		for(j=0;j<sutun;j++)
		{
			sifreMat[i][j]=dizi[sayac];
			
			sayac=sayac+1;                   //sayac 0 dan ba�l�yor, dizi nin i�indekiler s�rayla 2 boyutlu as�l sifrematrisimize yaz�l�yor
			
			if(sayac>53)        //dizinin [0,54) tane eleman� olacak. 54ten sonrakileri ascii kodu 0 olan null a e�itlemesi i�in if d�ng�s� kullan�ld�.
			{
				dizi[sayac]=0;
				
			}			
		}
				
	}  
	/*									printf("\n\n");
										for(i=0;i<satir;i++)          
										{
										for(j=0;j<sutun;j++) {
						
										printf("%c ",sifreMat[i][j]);          // --------> sifre matrisini yazd�ran kod. Kontrol ama�l� i�e yar�yor.
			
										}
	
											printf("\n"); }   */
	
	
	FILE *dosyaAdres;										//2 boyutlu bir matriste, istedigimiz karakterler random bir �ekilde yer ald���na g�re, �imdi bu matrisi bir text dosyas�na yazabiliriz.
	dosyaAdres = fopen(dosyaAdi,"w");     					//yazma ama�l�, (kullan�c�g�n verdi�i ad dosyaAdi'nda tutuluyor) dosyay� a�.(dosya olmad��� i�in olusturacak)
	
	fprintf(dosyaAdres,"%d %d",satir,sutun);				//ilk olarak text dosyas�na satir ve sutun say�s� yazd�r�l�yor (ki ilerde dosya okunurken sutun ve satir say�s�n�n bilgisi al�nabilsin)
	for(i=0;i<satir;i++)       //kullan�c�dan al�nan isimdeki text dosyas�na, matrisin yaz�lma i�lemi
	{
		for(j=0;j<sutun;j++)
		{
			
			fprintf(dosyaAdres,"%c",sifreMat[i][j]);  //charla yaz�l�yor ki ascii karakterleri, kod de�il de karakter �eklinde gelsin
			
		}
	
		
	}
	
	fclose(dosyaAdres);      //dosyay� kapat
	
	
	printf("Sifre matrisi dosyasi olusturuldu..");

	
	
	
	return 0;
}
