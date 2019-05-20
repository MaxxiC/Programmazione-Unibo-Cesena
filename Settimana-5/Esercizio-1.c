#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int intero = 5;
	char carattere = 'c';
	float virgola1 = 17.25f;
	double virgola2 = 10055.58562;
	int vtt[5] = { 10,20,30,40,50 };

	//dichiarazione puntatori
	int *pint = &intero;
	char *pcar = &carattere;
	float *pvirg1 = &virgola1;
	double *pvirg2 = &virgola2;
	int *pvtt = &vtt[0];

	//assegnazione valori con scanf
	printf("Scrivere il valore per la variabile di tipo char:  ");
	scanf("%c", &carattere);
	printf("\nScrivere il valore per la variabile di tipo int: ");
	scanf("%d", &intero);
	printf("\nScrivere il valore per la variabile di tipo float: ");
	scanf("%f", &virgola1);
	printf("\nScrivere il valore per la variabile di tipo double: ");
	scanf("%lf", &virgola2);

	//stampa puntatore a intero
    printf("\n\n\nLa variabile int vale:\n Diretto %d\n Indiretto %d \n", intero, *pint);
    printf("\nIn memoria alla posizione:\n Diretto %d\n Indiretto %d \n", &intero, &*pint);
	printf("L'indirizzo di memoria del puntatore e'==> %p\n\n", pint);

    printf("---------------");
	//stampa puntatore a char
    printf("\n\n\nLa variabile char vale:\n Diretto %c\n Indiretto %c \n", carattere, *pcar);
    printf("\nIn memoria alla posizione:\n Diretto %d\n Indiretto %d \n", &carattere, &*pcar);
    printf("L'indirizzo di memoria del puntatore e'==> %p\n\n", pcar);

    printf("---------------");
	//stampa puntatore a float
    printf("\n\n\nLa variabile float vale:\n Diretto %f\n Indiretto %f \n", virgola1, *pvirg1);
    printf("\nIn memoria alla posizione:\n Diretto %d\n Indiretto %d \n", &virgola1, &*pvirg1);
    printf("L'indirizzo di memoria del puntatore e'==> %p\n\n", pvirg1);

    printf("---------------");
	//stampa puntatore a double
    printf("\n\n\nLa variabile double vale:\n Diretto %f\n Indiretto %f \n", virgola2, *pvirg2);
    printf("\nIn memoria alla posizione:\n Diretto %d\n Indiretto %d \n", &virgola2, &*pvirg2);
    printf("L'indirizzo di memoria del puntatore e'==> %p\n\n", pvirg2);

    printf("---------------");
	//stampa puntatore a vettore
    printf("\n\n\nIl Primo elemento del vettore vale:\n Diretto %d\n Indiretto %d \n", vtt[0], *pvtt);
    printf("\nIn memoria alla posizione:\n Diretto %d\n Indiretto %d \n", &vtt[0], &*pvtt);
    printf("L'indirizzo di memoria del puntatore e'==> %p\n\n", pvtt);

    getchar();
	return 0;
}
