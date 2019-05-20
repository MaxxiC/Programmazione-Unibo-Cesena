#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

#define DIM 3

int leggi(void);/*leggi un elemento da tastiera effettuando gli opportuni controlli*/
void pulisci(void);/*mette in pausa l'elesecuzione e premendo INVIO pulisce lo schermo */

                            /**PILA INDICIZZATA STATICA*/
typedef struct pilaIS
{
    int vet[DIM];
    int dim;
} PilaIS;

int pilaIndStatica(void);/*gestisce il menu sulle operazioni da effetuare sulla lista indicizzata statica*/
void popIS(PilaIS*);/*lettura e conseguente eliminazione dell'elemento in testa*/
void pushIS(PilaIS*);/*inserimento di un elemento in testa*/

void statoIS(PilaIS const*);/*mostra stato della pila, non è considerato come uno stampa*/


                            /**PILA INDICIZZATA DINAMICA*/
typedef struct pilaID
{
    int *vet;
    int dim;/*dimensione logica*/
    int dimMax;/*dimensione fisica*/
} PilaID;


int pilaIndDinamica(void);/*gestisce il menu sulle operazioni da effetuare sulla lista indicizzata dinamica*/
void popID(PilaID*);/*lettura e conseguente eliminazione dell'elemento in testa*/
void pushID(PilaID*);/*inserimento di un elemento in testa*/

void ampliaID(PilaID*);/*esecuzione realloc raddoppiando stazio in memoria*/
void statoID(PilaID const*);/*mostra stato della pila, non è considerato come uno stampa*/


                            /**PILA COLLEGATA*/
typedef struct pilaC
{
    int info;
    struct pilaC *next;
} PilaC;


int pilaCollegata(void);/*gestisce il menu sulle operazioni da effetuare sulla lista collegata*/
PilaC* pushC(PilaC*);/*inserimento di un elemento in testa*/
PilaC* popC(PilaC*);/*lettura e conseguente eliminazione dell'elemento in testa*/

void statoC(PilaC const*);/*mostra stato della pila, non è considerato come uno stampa*/

#endif // PILA_H_INCLUDED
