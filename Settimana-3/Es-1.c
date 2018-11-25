#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define Lenghtvet 32

int main()
{
    //dichiaro il vettore
    int binario [Lenghtvet]={0};
    int valore,condizione,i,conta,risultato;
    char ripeti;

    valore=condizione=i=conta=risultato=0;

    do
    {
        do
        {
          printf("Numero da convertire in binario ->");
          fflush(stdin);
          scanf("%d", &valore);

            //Controllo del valore inserito
            if(valore<UINT_MAX&&valore>0)
            {
                    condizione=0;   //se è falsa il numero è buono
            }
            else
              if(valore<0||valore > UINT_MAX)
              {
                system("cls");
                printf("Errore Valore Non Gestito!\n");
                condizione=1;   //se è vera il numero non è valido
              }

        }
        while(condizione==1);   //se il numero non è velido riinizia

        //Eseguo la conversione
        for(i=0;valore!=0;i++)
        {
          conta++;
          risultato=valore/2;

          if(valore%2==0)
          {
              binario[i]=0;
          }
          else
            if(valore%2==1)
            {
              binario[i]=1;
            }

          valore=risultato;
        }

        system("cls");

        //Stampa del valore
        printf("In Binario si scrive  ");
        for(i=conta-1;i>=0;i--)
        {
          printf("%d",binario[i]);
        }
        printf("\n");

        
        printf("Rieseguire il programma? (Y|N) \n");
        fflush(stdin);
        scanf("%c", &ripeti);
        system("cls");

    }
    while(ripeti=='y'|| ripeti=='Y');





    return 0;
}
