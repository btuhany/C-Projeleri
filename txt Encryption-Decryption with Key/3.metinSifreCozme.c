#include <stdio.h>
#include <stdlib.h>



int main() {
int j,i;	
	
	int satirsayisi,sutunsayisi,Sayi;                                  //satirsayisi ve sutunsayisi, matris.txt dosyas�ndan okuduklar�m��z� yazaca��m�z yeni matrisin satir ve sutunsayisi olacak. Sayi ise Sifrelidosyadaki numaralar� tutan de�i�ken
	char Matris1[20],SifreliDosya[20],CozulmusDosya[20],M[9][9];       //Matris1,alaca��mz '�ifre matris text' dosyas� olacak, sifrelidosya=sifrelenmis dosya,cozulmusdosya=output dosyas�
	
	
	
	printf("Matrisin yazildigi dosya ismini uzantisi ile birlikte veriniz\n");
	scanf("%s",&Matris1);
	printf("Sifrelenmis metni iceren dosya ismini uzantisi ile birlikte veriniz\n");
	scanf("%s",&SifreliDosya);
	printf("Sifresi cozulmus metni icerecek dosya ismini uzantisi ile birlikte veriniz\n");
	scanf("%s",&CozulmusDosya);
	
	
	
	
	
	FILE *dosyaAdres;
	dosyaAdres = fopen(Matris1,"r");                                 //ald�g�m�z 'sifre matris text' dosyas� a��l�r.
	
	fscanf(dosyaAdres,"%d" "%d", &satirsayisi, &sutunsayisi);        //ilk �nce satirsayisi ve sutun say�s�n� program okuyup de�i�kenelere atama yapar. (Bu sat�r� 'tarama d�ng�s�' ne koymam�za gerek yok, ��nk� 2 tane int karakteri al�yor sadece)
	
	while (!feof(dosyaAdres))                                        //tarama i�lemi d�ng�s�
	{
	   for(i=0;i<satirsayisi;i++)                                   //sifre matris text'inden al�nan harfler yeni matrisimize yaz�l�r.
	   {
	   	 for(j=0;j<sutunsayisi;j++)
	   	 {
	   	 	fscanf(dosyaAdres,"%c", &M[i][j]);    		        	//text dosyas�ndaki her karakter(satir ve s�tun de�erleri d���ndaki,��nk� onlar� ilk �nce okumu�tu) , yeni matriste yer almaya ba�l�yor.
	   	 	
		 }
	   	
	   }
					
	}
	fclose(dosyaAdres);                                             // dosya kapan�r
	
	
	
		
							/*	for(i=0;i<satirsayisi;i++)
								{
			 
										for(j=0;j<sutunsayisi;j++)
	   											{
	   	 												printf("%c", M[i][j]);            //------->    Buras� konsolda �ifre matrisimizi g�rmek i�in.
	   	 	
												 }
											printf("\n ");
			
			
								}    */
	   
	   
	
	
	
	FILE *dosya2Adres;
	dosya2Adres = fopen(SifreliDosya,"r");                             //2. s�rada ald���m�z, Sifreli dosya texti a��l�r.(okuma ama�l�)
	
	FILE *dosya3Adres;                                            //Al�nan say�lar� i�ine yazmak ama�l� 3.dosyam�z(output) a��l�yor
	dosya3Adres = fopen(CozulmusDosya,"a");						
	
	while (!feof(dosya2Adres))                                        //�ifreli dosyay� tarama d�ng�s� ba�l�yor
	{               
		
		fscanf(dosya2Adres, "%d",&Sayi);                              //2. dosyadaki sayilar okunuyor (text'deki "bo�luk" karakterleri atlanarak okunuyor zaten)
																	  //Okunan sayi, sayi isimli de�i�kene atan�yor.
		
	
		i=(Sayi/10)-1;                                               //Al�nan say�n�n satir ve sutun numaras� hesaplan�yor
		j=(Sayi%10)-1;
		
		
		
							          								 // printf("%c",M[i][j]);          //----------> Buras� konsolda ��z�len �ifreyi g�rmek i�in.
		
		fprintf(dosya3Adres,"%c",M[i][j]);                          //Burada, say�n�n sutun ve satir numaras�n� bildi�imizden, ald���m�z ilk matrisi �a��r�yoruz, ve o satir ve sutunda hangi harf var ise bu harfi dosyan�n i�ine yaz diyoruz.
		
	
	   
		
	}
	
	
	fclose(dosya3Adres);                                         	//output dosyas� kapan�r
	fclose(dosya2Adres);                                             //2.dosya kapan�r
	
	printf("Sifre cozme tamamlanmistir");
	
	return 0;
}
