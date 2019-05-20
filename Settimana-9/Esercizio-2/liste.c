#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "liste.h"
#include <stdlib.h>
#include <string.h>

char *input_stringa(void) //funzione che prende in input stringhe dinamiche
{
	char * string = (char*)malloc(sizeof(char));
	int length = 0;
	do {
		string = realloc(string, (length + 1) * sizeof(char)); //alloco uno spazio per volta per ogni carattere
		string[length] = getchar();
		length++; //conta la lunghezza della stringa carattere per carattere
	} while (string[length - 1] != '\n'); //viene ripetuto il ciclo fino a quando non viene trovato il carattere di andata a capo
	string[length - 1] = '\0';
	return string;
}

int Empty(Listalibri * l)
{
	return(*l == NULL);  //controllo se la lista e' vuota
}
void Aggiungi_libro(Listalibri * l,int n)
{
	Listalibri libro;
	Listalibri ultimo_libro;
	if (!(ultimo_libro = (Listalibri)malloc(sizeof(Libro))))  //controllo valore di ritorno di malloc
	{
		printf("Memoria insufficiente!!");
		_getch();
		exit(1);
	}
	//inserimento dei dati del libro
	do {
		printf("Inserisci codice del libro: ");   
		ultimo_libro->codice = input_stringa();  //inserimento nome studente
	} while (ultimo_libro->codice[0] == '\0');
	do {
		printf("Inserisci titolo del libro: ");
		ultimo_libro->titolo = input_stringa();
	} while (ultimo_libro->titolo[0] == '\0');
	do {
		printf("Inserisci autore del libro: ");
		ultimo_libro->autore = input_stringa();
	} while (ultimo_libro->autore[0] == '\0');
	printf("Inserisci anno di pubblicazione del libro: ");
	while (scanf("%d", &ultimo_libro->anno) != 1 || ultimo_libro->anno < 1 || ultimo_libro->anno>2017) {      //inserimento scelta
		printf("Inserire un anno corretto:\n");
		while (getchar() != '\n'); //svuoto il buffer da eventuali \n lasciati dalla funzione scanf
	}
	while (getchar() != '\n');
	do {
		printf("Inserisci editore del libro: ");
		ultimo_libro->editore = input_stringa();
	} while (ultimo_libro->editore[0] == '\0');
	printf("Inserisci lunghezza del libro: ");
	while (scanf("%d", &ultimo_libro->lunghezza) != 1) {      //inserimento scelta
		printf("Inserire un numero intero:\n");
		while (getchar() != '\n'); //svuoto il buffer da eventuali \n lasciati dalla funzione scanf
	}
	while (getchar() != '\n');
	do {
		printf("Inserisci genere del libro: ");
		ultimo_libro->genere = input_stringa();
	} while (ultimo_libro->genere[0] == '\0');
	printf("Inserisci valutazione del libro(MIN 1, MAX 10): ");
	while (scanf("%d", &ultimo_libro->valutazione) != 1 || ultimo_libro->valutazione < 1 || ultimo_libro->valutazione >10) {      //inserimento scelta
		printf("Inserire un numero intero da 1 a 10:\n");
		while (getchar() != '\n'); //svuoto il buffer da eventuali \n lasciati dalla funzione scanf
	}
	while (getchar() != '\n');
	ultimo_libro->numero = n+1;
	ultimo_libro->next = NULL;
	if (*l == NULL)  //se la lista e' ancora vuota inserisco il libro in testa
		*l = ultimo_libro;
	else   
	{
		libro = *l;
		while (libro->next != NULL)   //altrimenti scorro la lista fino ad arrivare all'ultimo libro e inserisco il nuovo in coda
			libro = libro->next;
		libro->next = ultimo_libro;  //inserimento in coda

	}
}
void Cancella_libro(Listalibri * l, char *codice)
{
	Listalibri elem = *l;
	Listalibri tmp = *l;
	if (strcmp((*l)->codice, codice) == 0)
	{
		*l = (*l)->next;
		free(elem);
	}
	else
	{
		while (1) //continua fino a che non si raggiunge il break
		{
			if (elem != NULL && strcmp(elem->codice, codice) == 0)   //se il codice inserito da tastiera e il codice del libro corrispondono
			{
				tmp->next = elem->next;    //elimino il libro e assegno l'indirizzo di memoria del successivo a tmp
				free(elem);
				printf("Libro eliminato con successo!!\n");
				break;
			}
			else
				if (elem != NULL)
				{
					tmp = elem;  //salvo il valore di elem prima di incrementarlo in modo da poter effettuare il collegamento una volta eliminato il libro
					elem = elem->next;
				}
				else
					printf("Inserire un codice presente nella lista!!\n");
					break;
		}
	}
}
void stato_libri(Listalibri *l, int n)
{
	Listalibri stato = *l;
	if (!Empty(l))
	{
		printf("\nStato lista:\n");
	
		while (stato != NULL)
		{
			printf("%s%d%s", "\nLibro numero ", stato->numero, ":\n\n");
			printf("%s%s%s\n", "Codice ", " -> ", stato->codice);
			printf("%s%s%s\n", "Titolo ", " -> ", stato->titolo);
			printf("%s%s%s\n", "Autore ", " -> ", stato->autore);
			printf("%s%s%d\n", "Anno ", " -> ", stato->anno);
			printf("%s%s%s\n", "Editore ", " -> ", stato->editore);
			printf("%s%s%d\n", "Lunghezza ", " -> ", stato->lunghezza);
			printf("%s%s%s\n", "Genere ", " -> ", stato->genere);
			printf("%s%s%d\n", "Valutazione ", " -> ", stato->valutazione);
			stato = stato->next;
		}
	}
}
void stato_libri_val(Listalibri *l, int valutazione)
{
	Listalibri stato = *l;
	if (!Empty(l))
	{
		printf("%s%d\n\n", "\nVisualizzazione libri con valutazione maggiore o uguale a : ", valutazione);
		while (stato != NULL)
		{
			if (stato->valutazione >= valutazione)
			{
				printf("%s%d%s", "Libro numero ", stato->numero, ":\n\n");
				printf("%s%s%s\n", "Codice ", " -> ", stato->codice);
				printf("%s%s%s\n", "Titolo ", " -> ", stato->titolo);
				printf("%s%s%s\n", "Autore ", " -> ", stato->autore);
				printf("%s%s%d\n", "Anno ", " -> ", stato->anno);
				printf("%s%s%s\n", "Editore ", " -> ", stato->editore);
				printf("%s%s%d\n", "Lunghezza ", " -> ", stato->lunghezza);
				printf("%s%s%s\n", "Genere ", " -> ", stato->genere);
				printf("%s%s%d\n", "Valutazione ", " -> ", stato->valutazione);
			}
			stato = stato->next;
		}
	}
}