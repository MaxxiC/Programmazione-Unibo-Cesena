#include "pila.h"

int leggi()//leggi un elemento da tastiera effettuando gli opportuni controlli
{
    int n;
    while(scanf("%d",&n)!=1)
    {
        fflush(stdin);
        printf("Il valore inserito non e\' corretto\n\tReinserire valore: ");
    }
    fflush(stdin);
    return n;
}

void pulisci()//mette in pausa l'elesecuzione e premendo INVIO pulisce lo schermo
{
    fflush(stdin);
    printf("\n---------------------------------\n\n");
}


                                                        ///LISTA INDICIZZATA STATICA
int pilaIndStatica()//gestisce il menu sulle operazioni da effetuare sulla lista indicizzata statica
{
    PilaIS lis;
    lis.dim=-1;//si definisce così la lista vuota

    for(;;)//ciclo infinito uscita solo nel caso di scelta =3 o 4
    {
        int scelta;
        printf("\n -STATO della PILA");
        statoIS(&lis);
        printf("\n\n\t PILA INDICIZZIATA STATICA");
        printf("\n  1.inserisci nuovo elemento");
        printf("\n  2.stampare elemento in testa");
        printf("\n  3.ritornare al menu principale");
        printf("\n  4.terminare il programma");
        printf("\n\nInserisci valore relativo alla scelta: ");
        scelta=leggi();
        switch(scelta)
        {
            case 1: pushIS(&lis);break;
            case 2: popIS(&lis);break;
            case 3: printf("\n\tPROGRAMMA 'PILA INDICIZZATA STATICA' TERMINATO\n");return 1;
            case 4: return 0;
            default: printf("\nIl valore inserito non corrisponde a nessuna scelta");
        }
        if(scelta==1 ||scelta==2)
        {
            printf("\n -STATO della PILA");
            statoIS(&lis);
        }
        pulisci();
    }
}

void pushIS(PilaIS *lis)//inserimento di un elemento in testa
{
    if(lis->dim==DIM-1)//caso lista piena
        printf("\nImpossibile inserire nuovo elemento, MEMORIA INSUFFICIENTE\n");
    else
    {
        lis->dim++;
        for(int i=lis->dim;i>0;i--)
            lis->vet[i]=lis->vet[i-1];//scorrimento elementi del vettore per liberare la posizione testa
        printf("\nInserisci l'elemento da inserire in testa: ");
        lis->vet[0]=leggi();
    }
}

void popIS(PilaIS *lis)//lettura e conseguente eliminazione dell'elemento in testa
{
    if(lis->dim>-1)
    {
        printf("\nElemento in testa: %d\n",lis->vet[0]);
        for(int i=0;i<lis->dim;i++)
            lis->vet[i]=lis->vet[i+1];//scorrimento tutti gli elementi sovrascrivendo il primo
        lis->dim--;
    }
    else//caso lista vuota
        printf("\nImpossibile stampare elemento, PILA VUOTA\n");
}


void statoIS(PilaIS const *lis)//mostra stato della pila, non è considerato come uno stampa
{
    printf( "\n    Pila:\n    ");
    if(lis->dim!=-1)
        for(int i=0;i<=lis->dim;i++)
        {
            printf( " %d ",lis->vet[i]);
            printf("%c",i!=lis->dim?'-':' ');
        }
    else
        printf( " Vuota");
}

                                                        ///LISTA INDICIZZATA DINAMICA
int pilaIndDinamica()
{
    PilaID lis;
    //inizializzazione pila vuota
    lis.vet=(int*)malloc(DIM*sizeof(int));
    if (lis.vet == NULL) {
        printf("Error! Memory not allocated my dear..");
        exit(0);
    }
    lis.dim=-1;
    lis.dimMax=DIM;

    for(;;)//ciclo infinito uscita solo nel caso di scelta =3 o 4
    {
        int scelta;
        printf("\n  _STATO DELLA PILA PRIMA DELL'ESECUZIONE_");
        statoID(&lis);
        printf("\n\n\t_PILA INDICIZZIATA DINAMICA_");
        printf("\n  1.inserisci nuovo elemento");
        printf("\n  2.stampa elemento il testa");
        printf("\n  3.ritornare al menu principale");
        printf("\n  4.terminare il programma");
        printf("\n\nInserisci valore relativo alla scelta: ");
        scelta=leggi();
        switch(scelta)
        {
            case 1: pushID(&lis);break;
            case 2: popID(&lis);break;
            case 3: printf("\n\tPROGRAMMA 'PILA INDICIZZATA' STATICA TERMINATO\n");free(lis.vet);return 1;//eseguo la free prima di ritornare
            case 4: free(lis.vet);return 0;//eseguo la free prima di ritornare
            default: printf("\nIl valore inserito non corrisponde a nessuna scelta: ");
        }
        if(scelta==1 ||scelta==2)
        {
            printf("\n  _STATO DELLA PILA DOPO L'ESECUZIONE_");
            statoID(&lis);
        }

        pulisci();

    }
}

void pushID(PilaID *lis)//inserimento di un elemento in testa
{
    if(lis->dim==DIM-1)//nel caso di lista piena
        ampliaID(lis);

    lis->dim++;
    for(int i=lis->dim;i>0;i--)
        lis->vet[i]=lis->vet[i-1];//scorrimento elementi del vettore per liberare la posizione testa
    printf("\nInserisci l'elemento da inserire in testa: ");
    lis->vet[0]=leggi();
}

void popID(PilaID *lis)//lettura e conseguente eliminazione dell'elemento in testa
{
    if(lis->dim>-1)
    {
        printf("\nElemento in testa: %d\n",lis->vet[0]);
        for(int i=0;i<lis->dim;i++)
            lis->vet[i]=lis->vet[i+1];//scorrimento tutti gli elementi sovrascrivendo il primo
        lis->dim--;
    }
    else//caso pila vuota
        printf("\nImpossibile stampare elemento, PILA VUOTA\n");
}


void ampliaID(PilaID *lis)//esecuzione realloc raddoppiando stazio in memoria
{
    int *temp=realloc(lis->vet,2*(lis->dimMax)*sizeof(int));
    if(temp!=NULL)
    {
        lis->vet=temp;
        lis->dimMax*=2;
    }
    else//la realloc non è andata a buon fine
        printf("\nImpossibile inserire un elemento, MEMORIA INFUFFICIENTE");
}


void statoID(PilaID const *lis)//mostra stato della pila, non è considerato come uno stampa
{
    printf( "\n    Pila:\n    ");
    if(lis->dim!=-1)
        for(int i=0;i<=lis->dim;i++)
        {
            printf( " %d ",lis->vet[i]);
            printf("%c",i!=lis->dim?'-':' ');
        }
    else
        printf( " Vuota");
}

                                                        ///LISTA COLLEGATA
int pilaCollegata()
{
    PilaC *testa=NULL;//inizializzazione pila vuota
    for(;;)//ciclo infinito uscita solo nel caso di scelta =3 o 4
    {
        int scelta;
        printf("\n  _STATO DELLA PILA PRIMA DELL' ESECUZIONE_");
        statoC(testa);
        printf("\n\n\t_PILA COLLEGATA_");
        printf("\n  1.inserisci nuovo elemento");
        printf("\n  2.stampa elemento in testa");
        printf("\n  3.ritornare al menu principale");
        printf("\n  4.terminare il programma");
        printf("\n\nInserisci valore relativo alla scelta: ");
        scelta=leggi();
        switch(scelta)
        {
            case 1: testa=pushC(testa);break;
            case 2: testa=popC(testa);break;
            case 3: printf("\n\tPROGRAMMA 'PILA COLLEGATA' TERMINATO\n");return 1;
            case 4: return 0;
            default: printf("\nIl valore inserito non corrisponde a nessuna scelta..\n");

        }
        if(scelta==1 ||scelta==2)
        {
            printf("\n  _STATO DELLA PILA DOPO L'ESECUZIONE_");
            statoC(testa);
        }

        pulisci();
    }
}

PilaC* pushC(PilaC *testa)//inserimento di un elemento in testa
{
    PilaC *newelement;
    newelement=(PilaC*)malloc(sizeof(PilaC));//creazione nuova cella
    if(newelement!=NULL)
    {
        printf("\nInserisci l'elemento da inserire in testa: ");
        newelement->info=leggi();
        newelement->next=testa;//collegamento con primo elemento
        testa=newelement;//definizione nuova testa
        return testa;
    }
    else//caso non riuscita della malloc
    {
        printf("\nImpossibile inserire nuovo elemento, MEMORIA INSUFFICIENTE");
        return NULL;
    }
}

//lettura e conseguente eliminazione dell'elemento in testa
PilaC* popC(PilaC *testa)
{
    PilaC *temp=testa;
    if(temp==NULL)//la pila è vuota
        printf("\nImpossibile stampare elemento, PILA VUOTA\n");
    else
    {
        printf("\nElemento in testa: %d\n",testa->info);
        testa=testa->next;
        free(temp);

    }
    return testa;
}


void statoC(PilaC const *testa)//mostra stato della pila, non è considerato come uno stampa
{
    printf( "\n    Pila:\n    ");
    if(testa!=NULL)
        for(;testa!=NULL;testa=testa->next)
        {
            printf( " %d ",testa->info);
            printf("%c",testa->next!=NULL?'-':' ');
        }
    else
        printf(" Vuota");
}
