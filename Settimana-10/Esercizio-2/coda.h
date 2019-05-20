#ifndef CODA_H_INCLUDED
#define CODA_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

#define DIM 3

int leggi(void);/*leggi un elemento da tastiera effettuando gli opportuni controlli*/
void pulisci(void);/*mette in pausa l'elesecuzione e premendo INVIO pulisce lo schermo */

                            /**coda INDICIZZATA STATICA*/
typedef struct codaIS
{
    int vet[DIM];
    int dim;
} codaIS;

int codaIndStatica(void);/*gestisce il menu sulle operazioni da effetuare sulla lista indicizzata statica*/
void popIS(codaIS*);/*lettura e conseguente eliminazione dell'elemento in testa*/
void pushIS(codaIS*);/*inserimento di un elemento in testa*/

void statoIS(codaIS const*);/*mostra stato della coda, non è considerato come uno stampa*/


                            /**coda INDICIZZATA DINAMICA*/
typedef struct codaID
{
    int *vet;
    int dim;/*dimensione logica*/
    int dimMax;/*dimensione fisica*/
} codaID;


int codaIndDinamica(void);/*gestisce il menu sulle operazioni da effetuare sulla lista indicizzata dinamica*/
void popID(codaID*);/*lettura e conseguente eliminazione dell'elemento in testa*/
void pushID(codaID*);/*inserimento di un elemento in testa*/

void ampliaID(codaID*);/*esecuzione realloc raddoppiando stazio in memoria*/
void statoID(codaID const*);/*mostra stato della coda, non è considerato come uno stampa*/


                            /**coda COLLEGATA*/
typedef struct codaC
{
    int info;
    struct codaC *next;
} codaC;


int codaCollegata(void);/*gestisce il menu sulle operazioni da effetuare sulla lista collegata*/
codaC* pushC(codaC*);/*inserimento di un elemento in testa*/
codaC* popC(codaC*);/*lettura e conseguente eliminazione dell'elemento in testa*/

void statoC(codaC const*);/*mostra stato della coda, non è considerato come uno stampa*/

#endif
