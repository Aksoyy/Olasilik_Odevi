#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <time.h>

int ortalama(float dizi[],int boyut);

int main()
{
	int limit=0,say=0;
	printf("Lutfen verilerin limitini belirleyiniz = "); scanf("%d",&limit);
	
	float Veri_1[limit],Veri_2[limit],sonuc=0;
	
	for( say=0;say<limit;say+=1 )
	{
		Veri_1[say] = rand()%25;
		Veri_2[say] = rand()%25;
	}
	
	sonuc = ortalama(Veri_1,limit);
	printf("%d\n",sonuc);
	
	
	
	system("pause");
	return 0;
}

int ortalama(float dizi[],int boyut)
{
	int artma=0;
	float toplam=0;
	for( artma=0;artma<boyut;artma++ )
	{
		toplam += dizi[artma];
	}
	toplam=toplam/(float)boyut;
	return toplam;
}
