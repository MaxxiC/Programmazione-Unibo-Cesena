#define _CRT_SECURE_NO_WARNINGS 1
#include "liste.h"
#include <stdio.h>
#include <stdlib.h>

void main()
{
	Listalibri * libri = (Listalibri*)malloc(sizeof(Libro));
	int scelta = 0;
	int n_libri = 0;
	int val = 0;
	*libri = NULL;
	printf("La lista dei libri e' vuota!!\n");
	do {
		printf("\nMenu operazioni:\n\n");
		printf("1. Aggiungi libro\n");  //menu per la scelta delle operazioni
		printf("2. Cancella libro\n");
		printf("3. Visualizza tutti i libri n\n");
		printf("4. Visualizza in base alla valutazione\n");
		printf("5. Uscita programma\n");
		while (scanf("%d", &scelta) != 1) {      //inserimento scelta
			printf("Inserire un numero intero:\n");
			while (getchar() != '\n'); //svuoto il buffer da eventuali \n lasciati dalla funzione scanf
		}
		while (getchar() != '\n');

		system("cls");

		switch (scelta)
		{
		case 1:
			Aggiungi_libro(libri, n_libri);   //viene aggiunto un nuovo libro
			n_libri++;
			break;
		case 2:
			if (!Empty(libri))
			{
				printf("Inserisci il codice del libro da eliminare: ");  
				Cancella_libro(libri, input_stringa());   //viene cancellato un libro in base al suo codice  
			}
			else
				printf("La lista dei libri e' vuota!!\n");
			break;
		case 3:
			if (!Empty(libri))
			{
				stato_libri(libri, n_libri);    //visualizzo tutti i libri della lista
			}
			else
				printf("La lista dei libri e' vuota!!\n");
			break;
		case 4:
			if (!Empty(libri))
			{
				printf("Inserire una valutazione (MIN 1, MAX 10)\n");
				while (scanf("%d", &val) != 1 || val < 1 || val >10) {      //controllo valutazione tra 1 e 10
					printf("Inserire una valutazione corretta:\n");
					while (getchar() != '\n'); //svuoto il buffer da eventuali \n lasciati dalla funzione scanf
				}
				while (getchar() != '\n'); //svuoto il buffer da eventuali \n lasciati dalla funzione scanf
				stato_libri_val(libri, val);  //visualizzo tutti i libri con una certa valutazione
			}
			else
				printf("La lista dei libri e' vuota!!\n");
				break;
		case 5:
			printf("Uscita programma!!");
			break;
		default:
			printf("Inserire una scelta corretta!!\n");
		}
	} while (scelta != 5);
	free(libri); //dealloco la memoria 
}