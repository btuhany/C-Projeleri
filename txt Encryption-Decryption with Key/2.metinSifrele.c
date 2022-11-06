#include <stdio.h>
#include <stdlib.h>



int main() {
	
	int i,j,satirsayisi,sutunsayisi,sif;                                    //matris textinden elde edilecek s�tun ve satir de�erlerinin atanaca�� de�i�kenler, sif= hesaplanacak ve 3.dosyaya(output) yazd�ralacak karakter �ifresi
	char Matris1[20],Dosyaismi[20],SifrelenmisDosya[20],Harf, M[9][9];   //Matris1= �nceden olusturulan sifre matrisi, Dosyaismi=�ifrelenecek text, �ifrelenmi�Dosya=�ifrelenmi� haldeki text olacak  ***************
																		//M matrisi; kullan�c�n�n verdi�i, sifre matrisinin bulundugu text dosyas�ndan al�nacak �ifreyi kullanmak �zere yazaca��m�z matris.

	printf("Matrisin yazildigi dosya ismini uzantisi ile birlikte veriniz\n");
	scanf("%s",&Matris1); 												//Sifre matris dosyas�n�n ismini Matris1 de�i�keni i�erisinde tut.

	printf("Sifrelenecek metni iceren dosya ismini uzantisi ile birlikte veriniz\n");
	scanf("%s",&Dosyaismi);												//Sifrelenilecek dosyas�n�n ismini Dosyaismi de�i�keni i�erisinde tut.
	
	printf("Sifrelenmis metni icerecek dosya ismini uzantisi ile birlikte veriniz\n");
	scanf("%s",&SifrelenmisDosya);  									//Sifrelenmis dosya ismini ismini SifrelenmisDosya de�i�keni i�erisinde tut.
	
		
	
	FILE *dosyaAdres;
	dosyaAdres = fopen(Matris1,"r");                                   //sifre matris dosyas� okuma ama�l� a��l�r
	
	fscanf(dosyaAdres,"%d" "%d", &satirsayisi, &sutunsayisi);         //Text dosyas�ndan alaca��m�z matrisin, bu programdaki yeri i�in ilk �nce s�tun ve satir sayisini ��reniyoruz(d�ng�ye girmeden)  (bo�lu�u atlayarak ilk iki int karakterial)
																      //(Bu sat�r� 'tarama d�ng�s�' ne koymam�za gerek yok, ��nk� 2 tane int karakteri al�yor sadece)
	
	while (!feof(dosyaAdres))                                         //tarama i�lemi (metnin sonunu g�rene dek)
	{
	   for(i=0;i<satirsayisi;i++)								//ald�g�m�z satir ve sutun sayisi kadar i ve j d�necek. B�ylece random sifremiz aynen aktar�lacak, yeni matrise.
	   {
	   	 for(j=0;j<sutunsayisi;j++)
	   	 {
	   	 	fscanf(dosyaAdres,"%c", &M[i][j]);        //text dosyas�ndaki her karakter(satir ve s�tun de�erleri d���ndaki,��nk� onlar� ilk �nce okumu�tu) , yeni matriste yer almaya ba�l�yor. (bo�luk de�erini burda al�yor char de�i�keni ile)
	   	 	
		 }
	   	
	   }
					
	}											
												
 												/*	for(i=0;i<satirsayisi;i++)                      
	 												{
	   												  for(j=0;j<sutunsayisi;j++)
	  													{
	   	 													printf("%c ", M[i][j]);        // ----> Konsolda matrisi g�rmek i�in (kontrol ama�l�)
	   	 	
														}
	 												  printf ("\n");
	 												}
	
													printf ("\n\n");  	 */
	fclose(dosyaAdres);	                     //1.Dosyay� kapat
	
	
	
	FILE *dosya2Adres;							//Gerekli dosyalar�n adresi tan�mlan�r.
	FILE *dosya3Adres;						
	
	/* �NEML�: Program� yapmaya �al���rken fark ettik ki: E�er kullan�c�n verdi�i (�ifrelenmesi istenen) text dosyas�n�n, sonunda new line yoksa e�er, bir �ekilde bir hata ortaya ��k�yor ve yazd�raca��m�z dosyada
	textin son harfi ne ise, o harfin �ifresini 2 kez yazd�r�yor. Bunu �nlemek i�in kullan�c�dan alaca��m�z text dosyas�n�n sonuna bir adet new line ekliyoruz. Bu �ekilde herhangi bir problem ��km�yor. */
	
	dosya2Adres = fopen(Dosyaismi,"a");         // Kullan�c�n�n verdi�i, �ifrelenecek texti  ek yazd�rma ama�l� a�
	fprintf(dosya2Adres, "\n");					// ve new line ekle/olu�tur.
	fclose(dosya2Adres); 						// dosyay� kapat
	
	/* �imdi dosya �ifrelenmek i�in haz�r durumda */
	
	
				        	
	dosya3Adres = fopen(SifrelenmisDosya,"a");		// 3.dosya(�ifreli output) a��l�r.(yazma i�lemi yapmak i�in)  (d�ng�n�n i�inde a�m�yoruz ki, her d�nmede dosyay� a��p kapamas�n diye.
	dosya2Adres = fopen(Dosyaismi,"r");    		  //Sifrelenecek text okuma ama�l� a��l�r. 
	
	
	
		
	
	while (!feof(dosya2Adres)){                // Kullan�c�n�n verdi�i(�ifrelemek istedi�i) metin textini taranmaya ba�l�yor (metnin sonunu g�rene dek)
		
	
	fscanf(dosya2Adres, "%c",&Harf);             //Harf char �n�n i�ine textten okunan karakter atan�yor 
	
	  for(i=0;i<satirsayisi;i++)                //Burdaki 2'li for d�ng�s�, Al�nan harfin, M matrisinde hangi elemanla e�le�iyor, onu kontrol etmeye y�nelik.
	   {
	   	 for(j=0;j<sutunsayisi;j++)
	   	 {
	   	 	if(Harf==M[i][j])                                  //Okunan harf, matristeki harflerle kar��la�t�r�l�yor e�er ayn�ysa if d�ng�s�ne girecek, ayn� de�ilse ana d�ng� devam ediyor.
	   	 	{
	   	 		                            		
	   	 		sif=10*(i+1)+(j+1);                             //ilk �nce �ifresi hesaplan�yor    (satirsayisi+1)*10+(sutunsayisi+1)
	   	 		
	   	 		                                         						     // printf("%d ",sif);     // -------> konsolda �ifreyi g�rmek i�in
	   	 		                                         						     
	   	 		fprintf(dosya3Adres, " %d",sif);               //Output dosyas�na hesaplanan �ifreyi yaz. (" %d" bo�luk b�rakarak yazd�r�yoruz ki, de�ifreme yap�l�rken kolayl�k sa�lans�n.)
	   	 		                                           	
			}  	 	
		 }	   	
	   }	
	}
	
	fclose(dosya3Adres); // Output dosyas�n� kapat 
		
	
	fclose(dosya2Adres); // Text dosyas�n� kapat
	
	printf("\nSifreleme tamamlanmistir");

	
	return 0;
}
