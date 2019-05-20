#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 30

void main()
{
    //dichiarazioni vettori
    char str1[DIM+1];
    char str2[DIM+1];
    char sc[DIM+1];

    //dichiarazione variabili
    int i,j,z,o, l1,l2;
    int cont=0;
    char c;

    //input
    printf("Inserisci la frase principale (max 30 caratteri)\n");
    i=0;
    while((c=getchar()) != '\n' && i <=DIM)
    {
            str1[i] = c;
            i++;
    }

    str1[i] = '\0';
    //assegno a l1 la lunghezza della prima stringa
    l1 = i;
    printf("Inserisci la frase da sostituire (max 30 caratteri) \n");
    i=0;

    while((c=getchar()) != '\n' && i <=DIM)
    {
            str2[i] = c;
            i++;
    }
    str2[i] = '\0';
    l2= i;

    //controllo che la prima stringa sia maggiore della seconda
    if(l1<l2)
    {
        printf("%s\n", str1);// se e' piu grande stampo la prima stringa
    }
    else
    {
        z=0;
        for(i=0; i < l1 ; i++)//analizzo ogni carattere della prima stringa
            {

              cont = 0;
              if(str1[i] == str2[0])//cerco se esiste un carattere della prima stringa sia uguale al primo della seconda stringa
                {
                    for(j=0; j<l2; j++)
                    {
                        o = j+i;
                        if(str1[o]==str2[j])//controllo che i restanti elementi della stringa2 siano uguali ai restanti elementi della stringa 1
                        {
                            cont++;//aumento il contatore ogni colta che trovo una coerenza
                        }
                    }
                    if(cont == l2)//se il contatore e' uguale alla lunghezza di stringa inserisco il valore nella stringa di supporto e la incremento
                    {

                        sc[z]='*';
                        z++;
                        i+=cont-1;
                    }
                    else//se non e' uguale assegno alla stringa di supporto il valore della prima stringa
                    {
                        sc[z]=str1[i];
                        z++;
                    }
                }
                else
                {

                    sc[z]=str1[i];
                    z++;
                }
            }
    }



    sc[z]='\0';
    printf("%s\n",sc);
    system("pause");
    system("cls");

    printf("Inserisci la stringa principale (max 30 caratteri)\n");
    i=0;
    fflush(stdin);
    //prendo in input carattere per carattere e lo assegno a str1
    while((c=getchar()) != '\n' && i <=DIM)
    {
            str1[i] = c;
            i++;
    }
    str1[i] = '\0';//l'ultimo elemento del vettore dev essere \0
    l1 = i;//assegno
    printf("Inserisci l'occorrenza da cercare (max 30 caratteri)\n");
    i=0;
    fflush(stdin);
    while((c=getchar()) != '\n' && i <=DIM)
    {
            str2[i] = c;
            i++;
    }
    str2[i] = '\0';
    l2= i;
    int sw;
    char *p;
    l1=strlen(str1);//trovo la lunghezza della stringa utilizzando la funzione strlen
    l2=strlen(str2);
    do
    {
        sw=(int)strstr(str1,str2);//assegno il valore della funzione strstr a sw
        if(sw==(int)NULL)//se il valore e' NULL esco dal ciclo
        {
            break;
        }
        else
        {
            p=(int)sw;//dico al puntatore p di puntare all'indirizzo di sw
            *p='*';//sostituisco il valore della prima coerenza con *
            p++;//incremento il puntatore
            for(;*p!='\0';p++)//shifto a sinistra tutti i caratteri dopo p fino a \0
            {
                *p=*(p+l2-1);
            }

        }
    }
    while(sw!=(int)NULL);
    printf("%s \n", str1);//stampo a video la stringa
    system("pause");
}
