#include <stdio.h>
#include <stdlib.h>



int main() {
int j,i;	
	
	int satirsayisi,sutunsayisi,Sayi;                                  //satirsayisi ve sutunsayisi, matris.txt dosyasýndan okuduklarýmýýzý yazacaðýmýz yeni matrisin satir ve sutunsayisi olacak. Sayi ise Sifrelidosyadaki numaralarý tutan deðiþken
	char Matris1[20],SifreliDosya[20],CozulmusDosya[20],M[9][9];       //Matris1,alacaðýmz 'þifre matris text' dosyasý olacak, sifrelidosya=sifrelenmis dosya,cozulmusdosya=output dosyasý
	
	
	
	printf("Matrisin yazildigi dosya ismini uzantisi ile birlikte veriniz\n");
	scanf("%s",&Matris1);
	printf("Sifrelenmis metni iceren dosya ismini uzantisi ile birlikte veriniz\n");
	scanf("%s",&SifreliDosya);
	printf("Sifresi cozulmus metni icerecek dosya ismini uzantisi ile birlikte veriniz\n");
	scanf("%s",&CozulmusDosya);
	
	
	
	
	
	FILE *dosyaAdres;
	dosyaAdres = fopen(Matris1,"r");                                 //aldýgýmýz 'sifre matris text' dosyasý açýlýr.
	
	fscanf(dosyaAdres,"%d" "%d", &satirsayisi, &sutunsayisi);        //ilk önce satirsayisi ve sutun sayýsýný program okuyup deðiþkenelere atama yapar. (Bu satýrý 'tarama döngüsü' ne koymamýza gerek yok, çünkü 2 tane int karakteri alýyor sadece)
	
	while (!feof(dosyaAdres))                                        //tarama iþlemi döngüsü
	{
	   for(i=0;i<satirsayisi;i++)                                   //sifre matris text'inden alýnan harfler yeni matrisimize yazýlýr.
	   {
	   	 for(j=0;j<sutunsayisi;j++)
	   	 {
	   	 	fscanf(dosyaAdres,"%c", &M[i][j]);    		        	//text dosyasýndaki her karakter(satir ve sütun deðerleri dýþýndaki,çünkü onlarý ilk önce okumuþtu) , yeni matriste yer almaya baþlýyor.
	   	 	
		 }
	   	
	   }
					
	}
	fclose(dosyaAdres);                                             // dosya kapanýr
	
	
	
		
							/*	for(i=0;i<satirsayisi;i++)
								{
			 
										for(j=0;j<sutunsayisi;j++)
	   											{
	   	 												printf("%c", M[i][j]);            //------->    Burasý konsolda þifre matrisimizi görmek için.
	   	 	
												 }
											printf("\n ");
			
			
								}    */
	   
	   
	
	
	
	FILE *dosya2Adres;
	dosya2Adres = fopen(SifreliDosya,"r");                             //2. sýrada aldýðýmýz, Sifreli dosya texti açýlýr.(okuma amaçlý)
	
	FILE *dosya3Adres;                                            //Alýnan sayýlarý içine yazmak amaçlý 3.dosyamýz(output) açýlýyor
	dosya3Adres = fopen(CozulmusDosya,"a");						
	
	while (!feof(dosya2Adres))                                        //þifreli dosyayý tarama döngüsü baþlýyor
	{               
		
		fscanf(dosya2Adres, "%d",&Sayi);                              //2. dosyadaki sayilar okunuyor (text'deki "boþluk" karakterleri atlanarak okunuyor zaten)
																	  //Okunan sayi, sayi isimli deðiþkene atanýyor.
		
	
		i=(Sayi/10)-1;                                               //Alýnan sayýnýn satir ve sutun numarasý hesaplanýyor
		j=(Sayi%10)-1;
		
		
		
							          								 // printf("%c",M[i][j]);          //----------> Burasý konsolda çözülen þifreyi görmek için.
		
		fprintf(dosya3Adres,"%c",M[i][j]);                          //Burada, sayýnýn sutun ve satir numarasýný bildiðimizden, aldýðýmýz ilk matrisi çaðýrýyoruz, ve o satir ve sutunda hangi harf var ise bu harfi dosyanýn içine yaz diyoruz.
		
	
	   
		
	}
	
	
	fclose(dosya3Adres);                                         	//output dosyasý kapanýr
	fclose(dosya2Adres);                                             //2.dosya kapanýr
	
	printf("Sifre cozme tamamlanmistir");
	
	return 0;
}
