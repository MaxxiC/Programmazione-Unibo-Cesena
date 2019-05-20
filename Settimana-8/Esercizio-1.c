#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

#define NUM_ESAMI 5
#define NUM_Studenti 5

typedef struct {
	char materia[15];
	int voto;
}Elenco;

typedef struct {
	int numero_matricola;
	char nome[15];
	char cognome[15];
	int anno_imm;
	Elenco piano_studi[NUM_ESAMI];
}Studente;


int StampaStudente(Studente);
Studente Crea(int);

int main()
{
	//Inizialliazione variabili
	Studente vett[NUM_Studenti];
	int conta = 0;
	int exit = 0;
	int appoggio = 0;

	printf("Hai a disposizione un vettore di %d studenti\n\n", NUM_Studenti);

	do {
		//controllo per non uscire dalla dimensione del vettore
		if (conta == NUM_Studenti) {
			exit = 1;
		}
		else
		{
			//aggiunta obbligatoria del primo studente
			if (conta == 0)
				vett[conta++] = Crea(0);


			//aggiunta facoltativa dei seguenti
			//system("clear");
            printf("-------------------------------------------\n\n");
			printf("Per ora sono presenti i seguenti studenti nel vettore:\n");
			for (int i = 0; i < conta; i++)
			{
				printf("%d^ Matricola: %d\n", i + 1, vett[i].numero_matricola);
			}

			//richiesta di aggiunta
			printf("\nAggiungere un'altro studente? (0 no - 1 si)  ");
			scanf("%d", &appoggio);
			if (appoggio == 1)
			{
				//Controllo che non si inserisca due volte lo stesso studente controllando la matricola
				do
				{
					appoggio = 0;
                    char a;
                    int numero;
                    
                    printf("\nInserire i seguenti dati:\nNumero di matricola: ");
                    //Controllo sull'input, devono essere solo numeri
                    while(scanf("%d%c",&numero,&a) != 2 || a != '\n')
                    {
                        printf("Inserire solo numeri: ");
                        if(a == '\n')
                            scanf("%c",&a);
                        else
                        {
                            while(a != '\n')
                                scanf("%c",&a);
                        }
                    }
                    
                    for (int i = 0; i < conta; i++)
                    {
                        if (vett[i].numero_matricola == numero)
                            appoggio = 1;
                    }
                    
                    if (appoggio == 1)
                    {
                        printf("\n\nHai gia' inserito una studente con la medesima matricola... RIPROVARE\n\n");
                    }
                    else{
                        vett[conta++] = Crea(numero);
                    }
                    
                    
                    
//                    vett[conta++] = Crea();
//
//                    for (int i = 0; i < conta - 1; i++)
//                    {
//                        if (vett[i].numero_matricola == vett[conta - 1].numero_matricola)
//                            appoggio = 1;
//                    }
//
//                    if (appoggio == 1)
//                    {
//                        conta--;
//                        printf("\n\nHai gia' inserito una studente con la medesima matricola... REINSERIRLO\n\n");
//                    }
				} while (appoggio != 0);
			}
			else {
				exit = 1;
			}
		}
	} while (exit == 0);

	//
	//
	//Inserimento della matricola dello studente che si vuole visualizzare
	do {
		exit = 1;
		system("clear");
		printf("Ora hai un vettore di %d studenti,\n con i seguenti studenti nel vettore:\n", conta);
		for (int i = 0; i < conta; i++)
		{
			printf("%d^ Matricola: %d\n", i + 1, vett[i].numero_matricola);
		}

		printf("\nInserire il numero di matricola dello studente interessato: ");
		scanf("%d", &appoggio);

		for (int i = 0; i < conta; i++)
		{
			if (vett[i].numero_matricola != appoggio)
				exit = exit - 1;
			else
			{
				exit = exit + (10 * conta);
				appoggio = i;
			}
		}

	} while (exit < 1);


	//
	//
	//Visualizzazione dei dati della matricola cercata
	printf("Visualizzare tutti i dati dello studente selezionato (0) o aggiungere voti (1) ? (0|1)  ");
	scanf("%d", &exit);
	if (exit == 0)
	{
		exit = StampaStudente(vett[appoggio]);
		if (exit == 0)
			printf("Non sono stati inseriti voti per questo studente\n");

	}

	//
	//
	//Aggiunta di voti
	if (exit == 1)
	{
		if (vett[appoggio].piano_studi[0].voto < 0)
			printf("Per ora la matricola %d non ha voti assegnati", vett[appoggio].numero_matricola);
		else
		{
			printf("\nI Voti per ora inseriti della matricola %d sono:\n", vett[appoggio].numero_matricola);
			for (int i = 0; i < NUM_ESAMI; i++)
			{
				if (vett[appoggio].piano_studi[i].voto > 0)
				{
					printf("Voto di %s: %d\n",
						vett[appoggio].piano_studi[i].materia,
						vett[appoggio].piano_studi[i].voto
					);
					exit++;
				}
			}
		}

		//controllo se il vettore dei voti di questo studente è pieno o no
		if (exit - 1 == NUM_ESAMI)
			printf("\nA questo studente sono gia' stati asegnati tutti i voti.\n");
		else {

			//Aggiunta voti secondaria (terzo punto della consegna)
			int tot = NUM_ESAMI - (exit - 1);
			printf("Quante materie aggiungere (massimo %d)?", tot);
			scanf("%d", &exit);
			if (exit > 0 && exit < tot)
			{
				for (int i = NUM_ESAMI-tot; i <= exit; i++)
				{
					printf("\nNome materia n.%d: ", i + 1);
					scanf("%s", &vett[appoggio].piano_studi[i].materia);
					printf("Voto assegnato: ");
					scanf("%d", &vett[appoggio].piano_studi[i].voto);
				}
			}
		}
	}


	system("clear");
	printf("I dati della matricola %d ora sono:\n", vett[appoggio].numero_matricola);

	exit = StampaStudente(vett[appoggio]);


	printf("\nGrazie e addio..\n");
	system("pause");
	return 0;
}

Studente Crea(int nMatricola)
{
    //Variabili di appoggior
	Studente var;
	int app = 0;
    char a;

    if (nMatricola <= 0 || nMatricola >= 999999) {
        
        printf("\nInserire i seguenti dati:\nNumero di matricola: ");
        //Controllo sull'input, devono essere solo numeri
        while(scanf("%d%c",&app,&a) != 2 || a != '\n')
        {
            printf("Inserire solo numeri: ");
            if(a == '\n')
                scanf("%c",&a);
            else
            {
                while(a != '\n')
                    scanf("%c",&a);
            }
        }
        var.numero_matricola = app;
        
    }
    else{
        var.numero_matricola = nMatricola;
    }
    
	
    
    

	printf("Nome Studente: ");
	scanf("%s", &var.nome);
	printf("Cognome Studente: ");
	scanf("%s", &var.cognome);
    
	printf("Anno di Immatricolazione: ");
    while(scanf("%d%c",&app,&a) != 2 || a != '\n')
    {
        printf("Inserire solo numeri: ");
        if(a == '\n')
            scanf("%c",&a);
        else
        {
            while(a != '\n')
                scanf("%c",&a);
        }
    }
    var.anno_imm  = app;

    
    //Aggiunta Esami
    app = 0;
	do {
		printf("\nQuanti esami ha sostenuto su %d max?", NUM_ESAMI);
        while(scanf("%d%c",&app,&a) != 2 || a != '\n')
        {
            printf("Inserire solo numeri: ");
            if(a == '\n')
                scanf("%c",&a);
            else
            {
                while(a != '\n')
                    scanf("%c",&a);
            }
        }
	} while (app > NUM_ESAMI || app < 0);


	for (int i = 0; i < app; i++)
	{
		printf("\nNome materia n.%d: ", i + 1);
		scanf("%s", &var.piano_studi[i].materia);
        
		printf("Voto assegnato: ");
        while(scanf("%d%c",&app,&a) != 2 || a != '\n')
        {
            printf("Inserire solo numeri: ");
            if(a == '\n')
                scanf("%c",&a);
            else
            {
                while(a != '\n')
                    scanf("%c",&a);
            }
        }
        var.piano_studi[i].voto = app;
        
        
	}


	return var;
}

int StampaStudente(Studente std)
{
	int var = 0;

	printf("\nNumero di Matricola: %d \nNome: %s v\nCognome: %s \nAnno Immatriolazione: %d \n",
		std.numero_matricola,
		std.nome,
		std.cognome,
		std.anno_imm
	);

	for (int i = 0; i < NUM_ESAMI; i++)
	{
		if (std.piano_studi[i].voto > 0)
		{
			printf("Voto di %s: %d\n",
				std.piano_studi[i].materia,
				std.piano_studi[i].voto
			);
			var++;
		}
	}

	return var;
}
