#define _CRT_SECURE_NO_WARNINGS
#include "liste.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	//lista indicizzata (alloco lo spazio per una sola lista)
	TipoLista * lista = (TipoLista *)malloc(sizeof(TipoLista)); //lista statica
    if (lista == NULL) {
        printf("Error! Memory not allocated my dear..");
        exit(0);
    }
	TipoListaD * listaD = (TipoListaD *)malloc(sizeof(TipoLista));  //lista dinamica
    if (listaD == NULL) {
        printf("Error! Memory not allocated my dear..");
        exit(0);
    }
	ListaCollegata * listaC = (ListaCollegata)malloc(sizeof(TipoListaC)); //lista collegata
    if (listaC == NULL) {
        printf("Error! Memory not allocated my dear..");
        exit(0);
    }

	int scelta1 = 0;
	int scelta2 = 0;
	int n = 0;
	int i = 0;
	int conta = 0;


	do
	{
		do
		{
			if (scelta1 > 0 && scelta1 < 4)
			{
				break;
			}
			else
			{
				printf("\nMenu operazioni:\n");
				printf("1. Lista a vettore statico(massimo 10 elementi)\n");
				printf("2. Lista a vettore dinamico\n");
				printf("3. Liste collegate\n");
                printf("4. Uscita programma\n\n -Utente:");
				while (scanf("%d", &scelta1) != 1) {      //inserimento scelta
					printf("Inserire un numero intero:\n");
					while (getchar() != '\n');
				}

                printf("\n-----------------\n\n");

				switch (scelta1)
				{
				case 1: 
					if (Empty(lista))
						printf("La lista e' vuota!!\nSelezionare un'azione per riempirla!\n");
					lista->last = -1; //inizializzo l'ultimo elemento della lista statica a -1
					break;
				case 2:
					if (EmptyD(listaD))
						printf("La lista e' vuota!!\nSelezionare un'azione per riempirla!\n");
					listaD->info = (TipoElemListaD)malloc(sizeof(TipoElemLista));   //alloco spazio per il vettore dinamico
                        if (listaD->info == NULL) {
                            printf("Error! Memory not allocated my dear..");
                            exit(0);
                        }
					listaD->last = -1; //inizializzo l'ultimo elemento della lista dinamica a -1
					break;
				case 3:
					*listaC = NULL; //inizializzo la lista concatenata a NULL
					if (EmptyC(listaC))
						printf("La lista e' vuota!!\nSelezionare un'azione per riempirla!\n");
					break;
				case 4:
					exit(1);
				default:
					printf("Inserisci una scelta valida!!\n");
					break;
				}
			}
		} while (scelta1 != 4);
		printf("\nMenu operazioni:\n");
		printf("1. Aggiungi in testa\n");  //menu per la scelta delle operazioni
		printf("2. Aggiungi in coda\n");
		printf("3. Aggiungi dopo un elemento n\n");
		printf("4. Cancella testa\n");
		printf("5. Cancella coda\n");
		printf("6. Cancella prima occorenza elem n\n");
        printf("7. Uscita programma!\n\n -Utente: ");
		while (scanf("%d", &scelta2) != 1) {      //inserimento scelta
			printf("Inserire un numero intero:\n");
			while (getchar() != '\n'); //svuoto il buffer da eventuali \n lasciati dalla funzione scanf
		}

        printf("\n----------------\n\n");


		//in base alle relative scelte (1 2 o 3) utilizzo le rispettive liste: statica,dinamica,collegata
		//scelta 1: Aggiungo in testa
		//scelta 2: Aggiungo in coda
		//scelta 3: Aggiungo un elemento dopo un certo indice dato appartenente alla lista
		//scelta 4: Cancello la testa della lista
		//scelta 5: Cancello la coda della lista
		//scelta 6: Cancello la prima occorrenza di un elemento dato
		switch (scelta2)
		{
		case 1:  
			if (scelta1 == 1)
			{
				if (!Full(lista))
				{
					printf("Inserisci l'elemento da aggiugere: ");
					while (scanf("%d", &n) != 1) {     
						printf("Inserire un numero:\n");
						while (getchar() != '\n');
					}
					Inserisci_testa(lista, n);
				}
				else
					prt_err(lista);
			}
			if (scelta1 == 2)
			{
				printf("Inserisci l'elemento da aggiugere: ");
				while (scanf("%d", &n) != 1) {     
					printf("Inserire un numero:\n");
					while (getchar() != '\n');
				}
				Inserisci_testaD(listaD, n);
				resize_lista(listaD, listaD->last);
			}
			if (scelta1 == 3)
			{
				printf("Inserisci l'elemento da aggiugere: ");
				while (scanf("%d", &n) != 1) {    
					printf("Inserire un numero:\n");
					while (getchar() != '\n');
				}
				Aggiungi_testaC(listaC, n);
				conta++;
			}
			break;
		case 2:
			if (scelta1 == 1)
			{
				if (!Full(lista))
				{
					printf("Inserisci l'elemento da aggiugere: ");
					while (scanf("%d", &n) != 1) {    
						printf("Inserire un numero:\n");
						while (getchar() != '\n');
					}
					Inserisci_coda(lista, n);
				}
				else
					prt_err(lista);
			}

			if (scelta1 == 2)
			{
				printf("Inserisci l'elemento da aggiugere: ");
				while (scanf("%d", &n) != 1) {     
					printf("Inserire un numero:\n");
					while (getchar() != '\n');
				}
				Inserisci_codaD(listaD, n);
				resize_lista(listaD, listaD->last);
			}
			if (scelta1 == 3)
			{
				printf("Inserisci l'elemento da aggiugere: ");
				while (scanf("%d", &n) != 1) {    
					printf("Inserire un numero:\n");
					while (getchar() != '\n');
				}
				Aggiungi_codaC(listaC, n);
				conta++;
			}
			break;
		case 3:
			if (scelta1 == 1)
			{
				if (!Empty(lista))
				{
					printf("Inserisci un indice della lista: ");
					while (scanf("%d", &i) != 1 || i > lista->last || i > N - 1 || i < 0) {     
						printf("Inserire un indice valido:\n");
						while (getchar() != '\n');
					}
					printf("Inserisci l'elemento da aggiungere: ");
					while (scanf("%d", &n) != 1) {      
						printf("Inserire un numero intero:\n");
						while (getchar() != '\n');
					}
					Inserisci_dopo_elem(lista, i, n);
				}
				else
					prt_err(lista);
			}

			if (scelta1 == 2)
			{
				if (!EmptyD(listaD))
				{
					printf("Inserisci un indice della lista: ");
					while (scanf("%d", &i) != 1 || i > listaD->last || i < 0) {     
						printf("Inserire un indice valido:\n");
						while (getchar() != '\n');
					}
					printf("Inserisci l'elemento da aggiungere: ");
					while (scanf("%d", &n) != 1) {     
						printf("Inserire un numero intero:\n");
						while (getchar() != '\n');
					}
					Inserisci_dopo_elemD(listaD, i, n);
					resize_lista(listaD, listaD->last);
				}
				else
					prt_errD(listaD);

			}
			if (scelta1 == 3)
			{
				if (!EmptyC(listaC))
				{
					printf("Inserisci un indice della lista: ");
					while (scanf("%d", &i) != 1 || i >= conta || i < 0) {      
						printf("Inserire un indice valido:\n");
						while (getchar() != '\n');
					}
					printf("Inserisci l'elemento da aggiungere: ");
					while (scanf("%d", &n) != 1) {     
						printf("Inserire un numero intero:\n");
						while (getchar() != '\n');
					}
					Aggiungi_dopo_elemC(listaC, i, n);
					conta++;
				}
				else
					printf("\nLa lista e' vuota!! E' necessario inserire almeno un elemento!!\n");
			}

			break;
		case 4:
			if (scelta1 == 1)
			{
				if (!Empty(lista))
					Cancella_testa(lista);
				else
					prt_err(lista);
			}

			if (scelta1 == 2)
			{
				if (!EmptyD(listaD))
					Cancella_testaD(listaD);
				else
					prt_errD(listaD);
			}
			if (scelta1 == 3)
			{
				if (!EmptyC(listaC))
					Cancella_testaC(listaC);
				else
					printf("\nLa lista e' vuota!! E' necessario inserire almeno un elemento!!\n");
				conta--;
			}
			break;
		case 5:
			if (scelta1 == 1)
			{
				if (!Empty(lista))
					Cancella_coda(lista);
				else
					prt_err(lista);
			}

			if (scelta1 == 2)
			{
				if (!EmptyD(listaD))
					Cancella_codaD(listaD);
				else
					prt_errD(listaD);
			}
			if (scelta1 == 3)
			{
				if (!EmptyC(listaC))
					Cancella_codaC(listaC);
				else
					printf("\nLa lista e' vuota!! E' necessario inserire almeno un elemento!!\n");
				conta--;
			}
			break;
		case 6:
			if (scelta1 == 1)
			{
				if (!Empty(lista))
				{
					printf("Inserisci l'elemento da cancellare: ");
					while (scanf("%d", &n) != 1) {     
						printf("Inserire un numero:\n");
						while (getchar() != '\n');
					}
					Cancella_n(lista, n);
				}
				else
					prt_err(lista);
			}

			if (scelta1 == 2)
			{
				if (!EmptyD(listaD))
				{
					printf("Inserisci l'elemento da cancellare: ");
					while (scanf("%d", &n) != 1) {    
						printf("Inserire un numero:\n");
						while (getchar() != '\n');
					}
					Cancella_nD(listaD, n);
				}
				else
					prt_errD(listaD);
			}
			if (scelta1 == 3)
			{
				if (!EmptyC(listaC))
				{
					printf("Inserisci l'elemento da cancellare: ");
					while (scanf("%d", &n) != 1) {  
						printf("Inserire un numero:\n");
						while (getchar() != '\n');
					}
					Cancella_elemC(listaC, n);
				}
				else
					printf("\nLa lista e' vuota!! E' necessario inserire almeno un elemento!!\n");
				break;
			}
		case 7:
			exit(1);
			break;
		default: printf("Inserire una scelta valida!!\n");
			break;
		}
		//in base alla scelta stampo le relative liste
		if (scelta1 == 1)
		{
			if (scelta2 > 0 && scelta2 < 7 && !Empty(lista))
			{
				stato_lista(lista);
			}
		}
		if (scelta1 == 2)
		{
			if (scelta2 > 0 && scelta2 < 7 && !EmptyD(listaD))
			{
				stato_listaD(listaD);
			}
		}
		if (scelta1 == 3)
		{
			if (scelta2 > 0 && scelta2 < 7 && !EmptyD(listaD))
			{
				stato_listaC(listaC);
			}
		}
	} while (scelta2 != 7);


	free(lista);
	free(listaD);
	free(listaC);

	return 0;
}
