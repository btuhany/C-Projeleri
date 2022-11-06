#include <stdio.h>
#include <stdlib.h>



int main() {
	
	int i,j,satirsayisi,sutunsayisi,sif;                                    //matris textinden elde edilecek sütun ve satir deðerlerinin atanacaðý deðiþkenler, sif= hesaplanacak ve 3.dosyaya(output) yazdýralacak karakter þifresi
	char Matris1[20],Dosyaismi[20],SifrelenmisDosya[20],Harf, M[9][9];   //Matris1= Önceden olusturulan sifre matrisi, Dosyaismi=Þifrelenecek text, ÞifrelenmiþDosya=Þifrelenmiþ haldeki text olacak  ***************
																		//M matrisi; kullanýcýnýn verdiði, sifre matrisinin bulundugu text dosyasýndan alýnacak þifreyi kullanmak üzere yazacaðýmýz matris.

	printf("Matrisin yazildigi dosya ismini uzantisi ile birlikte veriniz\n");
	scanf("%s",&Matris1); 												//Sifre matris dosyasýnýn ismini Matris1 deðiþkeni içerisinde tut.

	printf("Sifrelenecek metni iceren dosya ismini uzantisi ile birlikte veriniz\n");
	scanf("%s",&Dosyaismi);												//Sifrelenilecek dosyasýnýn ismini Dosyaismi deðiþkeni içerisinde tut.
	
	printf("Sifrelenmis metni icerecek dosya ismini uzantisi ile birlikte veriniz\n");
	scanf("%s",&SifrelenmisDosya);  									//Sifrelenmis dosya ismini ismini SifrelenmisDosya deðiþkeni içerisinde tut.
	
		
	
	FILE *dosyaAdres;
	dosyaAdres = fopen(Matris1,"r");                                   //sifre matris dosyasý okuma amaçlý açýlýr
	
	fscanf(dosyaAdres,"%d" "%d", &satirsayisi, &sutunsayisi);         //Text dosyasýndan alacaðýmýz matrisin, bu programdaki yeri için ilk önce sütun ve satir sayisini öðreniyoruz(döngüye girmeden)  (boþluðu atlayarak ilk iki int karakterial)
																      //(Bu satýrý 'tarama döngüsü' ne koymamýza gerek yok, çünkü 2 tane int karakteri alýyor sadece)
	
	while (!feof(dosyaAdres))                                         //tarama iþlemi (metnin sonunu görene dek)
	{
	   for(i=0;i<satirsayisi;i++)								//aldýgýmýz satir ve sutun sayisi kadar i ve j dönecek. Böylece random sifremiz aynen aktarýlacak, yeni matrise.
	   {
	   	 for(j=0;j<sutunsayisi;j++)
	   	 {
	   	 	fscanf(dosyaAdres,"%c", &M[i][j]);        //text dosyasýndaki her karakter(satir ve sütun deðerleri dýþýndaki,çünkü onlarý ilk önce okumuþtu) , yeni matriste yer almaya baþlýyor. (boþluk deðerini burda alýyor char deðiþkeni ile)
	   	 	
		 }
	   	
	   }
					
	}											
												
 												/*	for(i=0;i<satirsayisi;i++)                      
	 												{
	   												  for(j=0;j<sutunsayisi;j++)
	  													{
	   	 													printf("%c ", M[i][j]);        // ----> Konsolda matrisi görmek için (kontrol amaçlý)
	   	 	
														}
	 												  printf ("\n");
	 												}
	
													printf ("\n\n");  	 */
	fclose(dosyaAdres);	                     //1.Dosyayý kapat
	
	
	
	FILE *dosya2Adres;							//Gerekli dosyalarýn adresi tanýmlanýr.
	FILE *dosya3Adres;						
	
	/* ÖNEMLÝ: Programý yapmaya çalýþýrken fark ettik ki: Eðer kullanýcýn verdiði (þifrelenmesi istenen) text dosyasýnýn, sonunda new line yoksa eðer, bir þekilde bir hata ortaya çýkýyor ve yazdýracaðýmýz dosyada
	textin son harfi ne ise, o harfin þifresini 2 kez yazdýrýyor. Bunu önlemek için kullanýcýdan alacaðýmýz text dosyasýnýn sonuna bir adet new line ekliyoruz. Bu þekilde herhangi bir problem çýkmýyor. */
	
	dosya2Adres = fopen(Dosyaismi,"a");         // Kullanýcýnýn verdiði, þifrelenecek texti  ek yazdýrma amaçlý aç
	fprintf(dosya2Adres, "\n");					// ve new line ekle/oluþtur.
	fclose(dosya2Adres); 						// dosyayý kapat
	
	/* Þimdi dosya þifrelenmek için hazýr durumda */
	
	
				        	
	dosya3Adres = fopen(SifrelenmisDosya,"a");		// 3.dosya(þifreli output) açýlýr.(yazma iþlemi yapmak için)  (döngünün içinde açmýyoruz ki, her dönmede dosyayý açýp kapamasýn diye.
	dosya2Adres = fopen(Dosyaismi,"r");    		  //Sifrelenecek text okuma amaçlý açýlýr. 
	
	
	
		
	
	while (!feof(dosya2Adres)){                // Kullanýcýnýn verdiði(þifrelemek istediði) metin textini taranmaya baþlýyor (metnin sonunu görene dek)
		
	
	fscanf(dosya2Adres, "%c",&Harf);             //Harf char ýnýn içine textten okunan karakter atanýyor 
	
	  for(i=0;i<satirsayisi;i++)                //Burdaki 2'li for döngüsü, Alýnan harfin, M matrisinde hangi elemanla eþleþiyor, onu kontrol etmeye yönelik.
	   {
	   	 for(j=0;j<sutunsayisi;j++)
	   	 {
	   	 	if(Harf==M[i][j])                                  //Okunan harf, matristeki harflerle karþýlaþtýrýlýyor eðer aynýysa if döngüsüne girecek, ayný deðilse ana döngü devam ediyor.
	   	 	{
	   	 		                            		
	   	 		sif=10*(i+1)+(j+1);                             //ilk önce þifresi hesaplanýyor    (satirsayisi+1)*10+(sutunsayisi+1)
	   	 		
	   	 		                                         						     // printf("%d ",sif);     // -------> konsolda þifreyi görmek için
	   	 		                                         						     
	   	 		fprintf(dosya3Adres, " %d",sif);               //Output dosyasýna hesaplanan þifreyi yaz. (" %d" boþluk býrakarak yazdýrýyoruz ki, deþifreme yapýlýrken kolaylýk saðlansýn.)
	   	 		                                           	
			}  	 	
		 }	   	
	   }	
	}
	
	fclose(dosya3Adres); // Output dosyasýný kapat 
		
	
	fclose(dosya2Adres); // Text dosyasýný kapat
	
	printf("\nSifreleme tamamlanmistir");

	
	return 0;
}
