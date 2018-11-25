#include <stdio.h>

int main ()
{
    int numero_studenti,scelta,i;
    float media_classe,conta_media,media_prov;
    char ripeti;

    do
    {
        //Tutte le variabili inizializzate a 0
        numero_studenti=scelta=i=media_classe=conta_media=media_prov=0;

        //Scelta del ciclo
        printf("Che Tipo Di Ciclo Vuoi Usare?\n");
        printf("1)FOR\n");
        printf("2)WHILE\n");
        printf("Scelta = ");
        fflush(stdin);
        scanf("%d",&scelta);
        system("cls");

        switch(scelta)
        {
          //Procedimento con l'uso del for()
          case 1:
            do
            {
                printf("Inserisci il numero degli studenti: ");
                scanf("%d",&numero_studenti);
            }
            while (numero_studenti<1);

            for(i=1;i<=numero_studenti;i++)
            {
                do
                {
                  printf("Inserisci Voto Studente numero%d\n",i);
                  scanf("%f",&conta_media);
                }
                while (conta_media<1||conta_media>10);
                //Controllo che il voto sia compreso tra 1 e 10

            media_prov+=conta_media;
            }

            media_classe = media_prov/numero_studenti;

            system("cls");
            printf("\n\n\n");
            printf("Media Della Classe = %.2f\n",media_classe);

            //Stampa del commento
            if(media_classe<6)
                printf("Media Classe Insufficente!\n");
            if(media_classe>=6&&media_classe<7)
                printf("Media Classe Sufficente!\n");
            if(media_classe>=7&&media_classe<8)
                printf("Media Classe Discreta!\n");
            if(media_classe>=8&&media_classe<9)
                printf("Media Classe Buona!\n");
            if(media_classe>=9&&media_classe<=10)
                printf("Media Classe Ottima!\n");
            break;

        //Stesso procedimento ma con l'uso del c'e' un while()
        case 2:


            do
            {
                printf("Inserisci il numero degli studenti: ");
                scanf("%d",&numero_studenti);
            }
            while (numero_studenti<1);

            i=1;
            while(i<=numero_studenti)
            {
                do
                {
                  printf("Inserisci Voto Studente numero%d\n",i);
                  scanf("%f",&conta_media);
                }
                while (conta_media<1||conta_media>10);

            media_prov+=conta_media;
            i++;
            }

            media_classe = media_prov/numero_studenti;
            system("cls");
            printf("\n\n\n");
            printf("Media Della Classe = %.2f\n",media_classe);

            if(media_classe<6)
                printf("Media Classe Insufficente!\n");
            if(media_classe>=6&&media_classe<7)
                printf("Media Classe Sufficente!\n");
            if(media_classe>=7&&media_classe<8)
                printf("Media Classe Discreta!\n");
            if(media_classe>=8&&media_classe<9)
                printf("Media Classe Buona!\n");
            if(media_classe>=9&&media_classe<=10)
                printf("Media Classe Ottima!\n");
            break;
        default:
            break;
        }

        //Codice per rieseguire il programma
        printf("Vuoi rieseguire il programma?(Y|N): \n");
        fflush(stdin);
        scanf("%c",&ripeti);
        system("cls");

    }while(ripeti=='y'|| ripeti=='Y');


    return 0;

}
