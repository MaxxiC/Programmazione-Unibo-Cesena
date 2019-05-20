#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int Fattoriale(int);

static int varPassaggio = 1;
static int End = 0;

int main()
{
	//Inizialliazione variabile
	int Num = 0;

	//Input utente
	printf("Di che numero vuoi calcolare il fattoriale ?");
	scanf("%d", &Num);

	//Calcolo e Stampa del risultato
	printf("Il fattoriale di %d e' %d\n", Num, Fattoriale(Num));

	system("pause");
	return 0;
}

int Fattoriale(int x)
{
	//variabile temporanea
	int ret = 0;

	//
	//Stampa delle info utili ad imparare la ricorsione
	if (End == 0)
		printf("Livello di ricorsione -%d:\n", varPassaggio++);

	printf("Variabile Ricevuta --> %d\n\n", x);

	//
	//Funzione di calcolo del fattoriale di un numero in maniera ricosiva
	if (x < 0)
	{
		printf("Non e' possibile calcolarlo per numeri negativi\n");
		return -1;	//non è possibile calcolarlo per numeri negativi
	}

	if (x == 0)
	{
		printf("---Ultima chiamata del processo ricorsivo e ritorno ai livelli superiori\n\n");
		ret = 1;
	}
	else
		ret = x * Fattoriale(x - 1);

	printf("Livello di ricorsione -%d:\n", --varPassaggio);
	printf("Variabile di ritorno --> %d\n\n", ret);

	return ret;
}