#include <stdio.h>
#include <stdlib.h>

#include "coda.h"

int main()
{
    //Scelta del tipo di lista da usare
    int cont = 0,scelta = 0;
    do
    {
        printf("\t_MENU SCELTA_");
        printf("\n  1.Lavorare con coda Statica");
        printf("\n  2.Lavorare con coda Dinamica");
        printf("\n  3.Lavorare con coda Collegata");
        printf("\n  4.Terminare il programma");
        printf("\n\nInserisci valore relativo alla scelta: ");
        scelta=leggi();
        printf("\n-------------------------------------\n\n");
        switch(scelta)
        {
            case 1: cont=codaIndStatica();break;
            case 2: cont=codaIndDinamica();break;
            case 3: cont=codaCollegata();break;
            case 4: cont=0;break;
            default:printf("\nIl valore inserito non corrisponde a nessuna scelta");
        }
        if(cont==1)
            pulisci();
        if(scelta==4 ||cont==0)
            printf("\n\tPROGRAMMA TERMINATO\n");
    }
    while(cont==1);
    return 0;
}
