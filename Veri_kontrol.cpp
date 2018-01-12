#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>

void grafik(int kontrol[],int boyut);
void harfli_not(int final[],int sonuc[],int boyut,int harf[]);
int standart(int sonuc[],int boyut);
void Not_dagilimi( float standart,int veri[],int boyut);
void Ogrenci_Basarisi(int basari[]);
void Ortalama(int ilk[],int son[],int boyut);

int main()
{
	int limit=0,yaz=0,standart_sonuc=0,harf[9]={0};
	
	printf("Lutfen Ogrenci Sayisini Belirleyiniz = "); scanf("%d",&limit);
	
	int vize[limit],final[limit],sonuc[limit];
	
	for( yaz=0;yaz<limit;yaz+=1 )
	{
		vize[yaz]=rand()%101;
		final[yaz]=rand()%101;
	}
	
	printf("-------------------------------------------------------------------------\n");
	printf("---OGRENCILERIN SINAV SONUCLARI------------------------------------------\n");

	for( yaz=0;yaz<limit;yaz++ )
	{
		sonuc[yaz]=(vize[yaz]+final[yaz])/2;
		printf("%d. Ogrencinin Notlari => Vize = %d\t Final = %d\t Ortalamasi = %d\n",yaz+1,vize[yaz],final[yaz],sonuc[yaz]);
	}

	printf("-------------------------------------------------------------------------\n");
	Ortalama(vize,final,limit);	
	
	printf("-------------------------------------------------------------------------\n");
	printf("OGRENCILERIN HARFI NOTLARI----------------------------------------------\n");
	printf("FF \t FD \t DD \t DC \t CC \t CB \t BB \t BA \t AA\n");
	harfli_not(final,sonuc,limit,harf);
	printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",harf[0],harf[1],harf[2],harf[3],harf[4],harf[5],harf[6],harf[7],harf[8]);
	
	printf("-------------------------------------------------------------------------\n");
	Ogrenci_Basarisi(harf);

	printf("-------------------------------------------------------------------------\n");
	printf("NOTLARIN STANDART SAPMA DEGERI = ");
	standart_sonuc = standart(sonuc,limit);
	printf("%d\n",standart_sonuc);
	
	Not_dagilimi(standart_sonuc,sonuc,limit);
	
	printf("-------------------------------------------------------------------------\n");
	printf("---OGRENCILERIN NOT DAGILIM GRAFIGI--------------------------------------\n");
	grafik(sonuc,limit);
	
	printf("-------------------------------------------------------------------------\n");
	
	system("pause");
	return 0;
}

void grafik(int kontrol[],int boyut)
{
	int yaz=0,yazdir[100]={0},say=0,kopya=0;
	
	for( yaz=0;yaz<boyut;yaz+=1 )
	{
		for( say=0;say<101;say++ )
		{
			if( say==kontrol[yaz] )
			{
				yazdir[say]=yazdir[say]+1;
			}
		}
	}
	
	for( yaz=0;yaz<100;yaz+=1 )
	{
		if( yazdir[yaz]!=0 )
		{
			kopya=yazdir[yaz];
			printf("%d = ",yaz);
			while( kopya>0 )
			{
				printf("*"); kopya--;
			}
			printf("\n");
		}
	}
}

int standart(int sonuc[],int boyut)
{
	int sayi=0;
	double toplam=0,topla=0;
	
	for( sayi=0;sayi<boyut;sayi+=1 )
	{
		toplam+=sonuc[sayi];
	}
	toplam=toplam/boyut;
	
	for( sayi=0;sayi<boyut;sayi++ )
	{
		topla+=pow(toplam-sonuc[sayi],2);
	}
	
	topla = sqrt(topla/boyut-1);
	return topla;
}

void harfli_not(int final[],int sonuc[],int boyut,int harf[])
{
	int a=0;
	
	for( a=0;a<boyut;a+=1 )
	{
		if( final[a]<45)
		{
			harf[0]+=1;
			continue;
		}

		if( sonuc[a]<25 )
		{
			harf[1]+=1;
		}
		else if( sonuc[a]<35 )
		{
			harf[2]+=1;
		}
		else if( sonuc[a]<45 )
		{
			harf[3]+=1;
		}
		else if( sonuc[a]<55 )
		{
			harf[4]+=1;
		}
		else if( sonuc[a]<65 )
		{
			harf[5]+=1;
		}
		else if( sonuc[a]<75 )
		{
			harf[6]+=1;
		}
		else if( sonuc[a]<85 )
		{
			harf[7]+=1;
		}
		else if( sonuc[a]<101)
		{
			harf[8]+=1;
		}
	}
}

void Not_dagilimi( float standart,int veri[],int boyut)
{
	int artma=0;
	float sapma=0;
	
	for( artma=0;artma<boyut;artma++ )
	{
		sapma += (float)veri[artma];
	}
	sapma /= boyut;
	
	printf("----------------------------------------------------------\n");
	printf("Notlarin ortalama degeri = %.3f\n",sapma);
	printf("FF \t FD \t DD \t DC \t CC \t CB \t BB \t BA \t AA \n");
	printf("%.2f \t %.2f \t %.2f \t %.2f \t %.2f \t %.2f \t %.2f \t %.2f \t%.2f \n",
	sapma-(standart*4),sapma-(standart*3),sapma-(standart*2),sapma-standart,sapma,
	sapma+standart,sapma+(standart*2),sapma+(standart*3),sapma+(standart*4));
}

void Ogrenci_Basarisi(int basari[])
{
	int say,mutlak=0,kosullu=0;
	
	kosullu=basari[3];
	
	for( say=4;say<=8;say+=1 )
	{
		kosullu += basari[say];
		mutlak += basari[say];
	}
	
	printf("DERSI GECEN OGRENCI SAYISI = %d\n",mutlak);
	printf("DERSI KOSULLU GECEN OGRENCI SAYISI = %d\n",kosullu);
}

void Ortalama(int ilk[],int son[],int boyut)
{
	float sonuc_ilk=0,sonuc_son=0;
	int artma=0;
	
	for( artma=0;artma<boyut;artma+=1 )
	{
		sonuc_ilk += ilk[artma];
		sonuc_son += son[artma];
	}
	sonuc_ilk /= boyut; sonuc_son /= boyut;
	
	printf("Vize Notlarinin Ortalamasi = %.3f\n",sonuc_ilk);
	printf("Final Notlarinin Ortalamasi = %.3f\n",sonuc_son);
}
