#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>



int IsPrimo(int);

int main()
{
	//variabili vettore
	int Num = 0;
	int i,cont = 0;
	int *vett = (int *)malloc(sizeof(int));;

	printf("Fino a che numero verificare la presenza di numeri primi? ");
	scanf("%d", &Num);

	for (i = 2; i < Num; i++)
	{
		if (IsPrimo(i) %2 == 1)
		{
			vett = (int *)realloc(vett, (sizeof(int)*(cont + 1)));
			vett[cont++] = i;
		}
	}

	//Aggiunta del 
	while (i != 1)
	{
		if (IsPrimo(Num) == 1)
		{
			vett = (int *)realloc(vett, (sizeof(int)*(cont + 1)));
			vett[cont++] = Num;
			i = 1;
		}
		Num++;
	}

	//Stampa
	printf("Numeri primi:\n");
	for (i = 0; i < cont-1; i++)
		printf(" %d	", vett[i]);
	printf("\nIl piu' vicino successivo e' %d\n %d totali trovati\n\n", vett[i], cont);


	system("pause");
	return 0;
}

int IsPrimo(int x)
{
	int i = 0;
	for (i = 2; i < x / 2; i++)
		if (x%i == 0)
			return 0;

	return 1;
}