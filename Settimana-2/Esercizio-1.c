#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Dichiaro e inizializzo 4 vettori per le partenze e gli ariivi, con le posizioni che combaciano
    float partenzeMatt[4]={8.00,9.43,11.19,12.47};
    float partenzePome[4]={2.00,3.45,7.00,9.45};
    float arriviMatt[4]={10.16,11.52,1.31,3.00};
    float arriviPome[4]={4.08,5.55,9.20,11.58};

    float orario;
    int i=0;
    char ripeti;

    //Ciclo do-while
    do
    {
        printf("Inserisci l'orario di partenza del volo in formato 24h (esteso),\ndividendo le ore dai minuti Es.(15.30)\n");
        fflush(stdin);
        //libero il buffer prima di leggere dati di input da tastiera
        scanf("%f",&orario);

        //Controllo del formato dell'ora inserita
        if(orario>12)
        {
            orario-=12;

            while(i<4)
            {
              //Controllo il volo successivo
                if(orario<partenzePome[i])
                {
                    printf("Il prossimo volo e' in partenza alle ore: %.2fPM l'arrivo previsto e' per le ore: %.2fPM\n",partenzePome[i],arriviPome[i]);
                    i=4;
                }
                else
                {
                    i++;
                }
            }
            i=0;
        }
        else
        {
            while(i<4)
            {
                //Controllo della corretta posizione e stampa a video
                if(orario<partenzeMatt[i])
                {
                    if(orario>partenzeMatt[2])
                        printf("Il prossimo volo in partenza e' alle ore: %.2fAM con arrivo previsto per le ore: %.2fPM\n",partenzeMatt[i],arriviMatt[i]);
                    else
                        printf("Il prossimo volo in partenza e' alle ore: %.2fAM con arrivo previsto per le ore: %.2fAM\n",partenzeMatt[i],arriviMatt[i]);
                    i=4;
                }
                else
                {
                    i++;
                }
            }
            i=0;
        }
        //Opzione per riiniziare il programma
        printf("Vuoi immettere nuovi orari?(Y|N): \n");
        fflush(stdin);
        scanf("%c",&ripeti);
        system("cls");

    }while(ripeti=='y'|| ripeti=='Y');

return 0;
}
