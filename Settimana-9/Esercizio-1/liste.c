#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "liste.h"
#include <stdlib.h>
#define EMPTYLIST -1

int Full(TipoLista *l)  //controllo se la lista e' piena (statico)
{
	return (l->last == N - 1);
}
int Empty(TipoLista *l) //controllo se la lista e' vuota (statico)
{
	return (l->last == EMPTYLIST);
}
int EmptyD(TipoListaD *l) //controllo se la lista e' vuota (dinamico)
{
	return (l->last == EMPTYLIST);
}
int EmptyC(ListaCollegata*l) //controllo se la lista e' vuota (collegata)
{
	return (*l == NULL);
}
void Inserisci_dopo_elem(TipoLista *l, int index, TipoElemLista x) //inserisco elemento dopo un certo indice spostando gli altri(statico)
{
	int i;
	for (i = l->last + 1; i > index + 1; i--)
		l->info[i] = l->info[i - 1];
	l->info[i] = x;
	l->last++;
}
void Cancella_testa(TipoLista * l)  //cancello testa(statico)
{
	int i;
	for (i = 0; i < l->last; i++)
		l->info[i] = l->info[i + 1];
	l->last--;
}

void Cancella_coda(TipoLista * l) //cancello coda(statico)
{
	l->last--;
}
void Cancella_n(TipoLista *l, TipoElemLista x) //cancello elemento dopo un dato elemento spostando gli altri(statico)
{
	int i;
	int trovato = 0;
	for (i = 0; i <= l->last; i++)
	{
		if (l->info[i] == x)
		{
			for (; i <= l->last; i++)
			{
				l->info[i] = l->info[i + 1];
			}
			trovato = 1;
			l->last--;
		}
	}
	if (!trovato)
		printf("\nElemento non presente nella lista!!\n");

}
void Inserisci_testa(TipoLista *l, TipoElemLista x) //inserisco testa(statico)
{
	int i;
	for (i = l->last; i >= 0; i--)
		l->info[i + 1] = l->info[i];
	l->info[0] = x;
	l->last++;
}
void Inserisci_coda(TipoLista *l, TipoElemLista x) //inserisco coda(statico)
{
	l->info[l->last + 1] = x;
	l->last++;
}
void prt_err(TipoLista *l) //funzione che stampa i possibili errori(statico)
{
	if (Full(l))
		printf("\nLa lista e' piena!! E' necessario cancellare un elemento!!\n");
	else
		if (Empty(l))
			printf("\nLa lista e' vuota!! E' necessario inserire almeno un elemento!!\n");
}
void resize_lista(TipoElemListaD *l, int last) //ridimensiono la lista(dinamico)
{
	last += 2;
	if (!(l = (TipoElemListaD *)realloc(l, last * sizeof(TipoElemLista))))
	{
        printf("Memoria insufficiente!!");
		exit(1);
	}
}
void stato_lista(TipoLista *l) //statmpa  stato lista(statico)
{
	int i;
	printf("Stato lista:\n\n");
	for (i = 0; i <= l->last; i++)
	{
		printf("%d%s%d\n", i, " -> ", l->info[i]);
	}
}
void Inserisci_dopo_elemD(TipoListaD *l, int index, TipoElemLista x) //inserisco elemento dopo un certo indice spostando gli altri(dinamico)
{
	int i;
	for (i = l->last + 1; i > index + 1; i--)
		l->info[i] = l->info[i - 1];
	l->info[i] = x;
	l->last++;
}
void Cancella_testaD(TipoListaD * l) //cancello testa(dinamico)
{
	int i;
	for (i = 0; i < l->last; i++)
		l->info[i] = l->info[i + 1];
	l->last--;
}

void Cancella_codaD(TipoListaD * l) //cancello coda(dinamico)
{
	l->last--;
}
void Cancella_nD(TipoListaD *l, TipoElemLista x) //cancello elemento dopo un dato elemento spostando gli altri(statico)
{
	int i;
	int trovato = 0;
	for (i = 0; i <= l->last; i++)
	{
		if (l->info[i] == x)
		{
			for (; i <= l->last; i++)
			{
				l->info[i] = l->info[i + 1];
			}
			trovato = 1;
			l->last--;
		}
	}
	if (!trovato)
		printf("\nElemento non presente nella lista!!\n");

}
void Inserisci_testaD(TipoListaD *l, TipoElemLista x) //inserisco testa(dinamico)
{
	int i;
	for (i = l->last; i >= 0; i--)
		l->info[i + 1] = l->info[i];
	l->info[0] = x;
	l->last++;
}
void Inserisci_codaD(TipoListaD *l, TipoElemLista x) //inserisco coda(dinamico)
{
	l->info[l->last + 1] = x;
	l->last++;
}
void prt_errD(TipoListaD *l)//funzione che stampa i possibili errori(dinamico)
{
	if (EmptyD(l))
		printf("\nLa lista e' vuota!! E' necessario inserire almeno un elemento!!\n");
}
void stato_listaD(TipoListaD *l) //funzione che stampa lo stato lista(dinamico)
{
	int i;
	printf("Stato lista:\n\n");
	for (i = 0; i <= l->last; i++)
	{
		printf("%d%s%d\n", i, " -> ", l->info[i]);
	}
}
void Aggiungi_testaC(ListaCollegata *l, TipoElemLista x ) //funzione che aggiunge testa(collegata)
{
	ListaCollegata testa;
	if (!(testa = (ListaCollegata)malloc(sizeof(TipoListaC))))
	{
		printf("Memoria insufficiente!!");
		exit(1);
	}
	testa->info = x;
	testa->next = *l;
	*l = testa;
}
void Aggiungi_codaC(ListaCollegata *l, TipoElemLista x) //funzione che aggiunge coda(collegata)
{
	ListaCollegata last;
	ListaCollegata scorri_lista;
	if (!(last = (ListaCollegata)malloc(sizeof(TipoListaC))))
	{
		printf("Memoria insufficiente!!");
		exit(1);
	}
	last->info = x;
	last->next = NULL;
	if (*l == NULL)
		*l = last;
	else
	{
		scorri_lista = *l;
		while (scorri_lista->next != NULL)
			scorri_lista = scorri_lista->next;
		scorri_lista->next = last;//lavoro sull'indirizzo dell'ultima struct 
	}
}
void Aggiungi_dopo_elemC(ListaCollegata *l, int index, TipoElemLista x) //funzione che aggiunge dopo un dato elemento(collegata)
{
	int i;
	ListaCollegata elemento;
	ListaCollegata scorri_lista = *l;
	if (!(elemento = (ListaCollegata)malloc(sizeof(TipoListaC))))
	{
		printf("Memoria insufficiente!!");
		exit(1);
	}
	for (i = 0; i < index; i++)
	{
		scorri_lista = scorri_lista->next;
	}
	elemento->info = x;
	elemento->next = scorri_lista->next;
	scorri_lista->next = elemento;
}
void Cancella_testaC(ListaCollegata *l) //funzione che cancella testa(collegata)
{
	ListaCollegata testa = *l;
	*l = (*l)->next;
	free(testa);
}
void Cancella_codaC(ListaCollegata *l)//funzione che cancella coda(collegata)
{
	ListaCollegata coda = *l;
	if ((*l)->next == NULL)
		*l = NULL;
	else
	{
		while (coda->next != NULL)
			coda = coda->next;
		free(coda);
	}
}
void Cancella_elemC(ListaCollegata *l, TipoElemLista x) //funzione che cancella un dato elemento(collegata)
{
	ListaCollegata elem = *l;
	ListaCollegata tmp = *l;
	if ((*l)->info == x)
	{
		*l = (*l)->next;
		free(elem);
	}
	else
	{
		while (1)
		{
			if (elem != NULL && elem->info == x)
			{
				tmp->next = elem->next;
				free(elem);
				break;
			}
			else
				if (elem != NULL)
				{
					tmp = elem;
					elem = elem->next;
				}
				else
					break;
		}
	}
}
void stato_listaC(ListaCollegata *l) //funzione che stampa stato lista(collegata)
{
    ListaCollegata stato = *l;
	int i = 0;
	if (!EmptyC(l))
	{
		printf("Stato lista:\n\n");
		while (stato != NULL)
		{
			printf("%d%s%d\n", i, " -> ", stato->info);
			i++;
			stato = stato->next;
		}
	}
}
