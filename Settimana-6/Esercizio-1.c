#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define gg 5




void ordina_vettore(int*, int);
int Cerca(int[], int, int);

int indici[gg];

int main()
{
	//variabili vettore
	int vtt[gg];
	int *p = &vtt[0];
	int lenght = gg;

	//variabili utili
	int i;
	int elemento = 0;
	char ch;







	//riempimento vettore
	srand(time(NULL));
	do {
		system("cls");
		for (i = 0; i < gg; i++)
		{
			vtt[i] = (rand() % 10) + 1;
		}


		printf_s("Il vettore è inizzializzato con i seguenti valori int:\n");

		for (i = 0; i < 5; i++)
		{
			printf_s("%d)- %d\n", i, vtt[i]);
		}

		printf("\n Generare nuovi numeri? 0(no)-1(si)");
		elemento++;
	} while ((ch = getchar()) != '0');


	//Stampa a video del vettore scelto
	system("cls");
	printf_s("Il vettore è inizzializzato con i seguenti valori int:\n");
	for (i = 0; i < 5; i++)
	{
		printf_s("%d)- %d\n", i, vtt[i]);
	}

	//Input - elemento da cercare
	printf("\nChe valore vuoi cercare nel vettore?\n");
	scanf_s("%d", &elemento);

	//Richiamo della funzione
	elemento = Cerca(p, lenght, elemento);






	//Stampa dei risultati
	if (elemento == -1)
	{
		printf("\n-- Il valore scelto non e' presente nel vettore\n");
	}
	else
	{
		printf("\nElemento trovato in posizione:\n");
		for (i = 0; i < elemento; i++)
		{
			printf("- %d\n", indici[i]);
		}
	}

	//
	//
	//Ordinamento del vettore e riesecuzione della funzione
	ordina_vettore(p, lenght);
	system("pause");
	system("cls");
	printf("Il vettore e' stato ordinato... \n---------\n");
	for (i = 0; i < 5; i++)
	{
		printf_s("%d)- %d\n", i, vtt[i]);
	}
	printf("\nChe valore vuoi cercare nel vettore?\n");
	scanf_s("%d", &elemento);

	//Richiamo della funzione
	elemento = Cerca(p, lenght, elemento);
	if (elemento == -1)
	{
		printf("\n-- Il valore scelto non e' presente nel vettore\n");
	}
	else
	{
		printf("\nElemento trovato in posizione:\n");
		for (i = 0; i < elemento; i++)
		{
			printf("- %d\n", indici[i]);
		}
	}



	system("pause");
	return 0;
}



int Cerca(int vtt[], int length, int elemento)
{
	int out = 0;
	int j = 0;

	for (int i = 0; i < length; i++)
	{
		if (vtt[i] == elemento)
		{
			indici[j++] = i;
			out++;
		}
	}

	if (out == 0)
	{
		out = -1;
	}

	return out;
}


void ordina_vettore(int *vttOrdinato, int lenght)
{

	int a, b, c;

	//ordinamento con bubble sort
	for (a = 0; a < (lenght - 1); a++)
	{
		for (b = 0; b < lenght - a - 1; b++)
		{
			if (*(vttOrdinato + b) > *(vttOrdinato + b + 1))
			{
				c = *(vttOrdinato + b);
				*(vttOrdinato + b) = *(vttOrdinato + b + 1);
				*(vttOrdinato + b + 1) = c;
			}
		}
	}
}