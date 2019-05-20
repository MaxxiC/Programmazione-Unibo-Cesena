#include <stdio.h>
#include <ctype.h>
int main ()
{
	int user1[31] = {0};
	int user2[31] = {0};
	int monthLen, Mese, monthCorrect, dayCorrect=0, i, j = 0;
	char bisest;
	int day = 0;

	do
	{
		fflush(stdin);
		printf("Inserire il numero del mese desiderato: (da 1 a 12)");

		//Controllo del mese
		if (scanf("%d", &Mese) == 0 || Mese < 1 || Mese >12)
		{
			printf("Non hai inserito un numero di mese corretto. Riprova\n");
			monthCorrect = 0;
		}
		else
		{
			monthCorrect = 1;
		}
	}
	while (monthCorrect == 0);

	//assegno il numero di giorni in base al mese inserito
	 switch (Mese)
	 {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			 monthLen = 31;
			 break;
		case 4:
		case 6:
		case 9:
		case 11:
			 monthLen = 30;
			 break;
		 case 2:
			 printf("L'anno e' bisestile? s/n __ ");
			 scanf("%s", &bisest);
			 if (bisest == 's')
			 {
				 monthLen = 29;
			 }
			 else
			 {
				 monthLen = 28;
			 }
			 break;
	 }



	for (i = 1; i <= 2; i++)
	{
		printf("\n Inserire i giorni liberi per l'Utente %d, compresi tra 1 e %d. Scrivere 0 per terminare.\n",i, monthLen);

		do
		{
			do
			{
				fflush(stdin);
				printf("-> ");

				if ((scanf("%d", &day) == 1) && day >= 0 && day <= monthLen)
				{
					if (i == 1)
					{
						user1[day - 1] = 1;
					}
					else
					{
						if (i == 2)
						{
						user2[day - 1] = 1;
						}
					}
					dayCorrect = 1;
				}
				else
				{
					printf("Non e' estato inserito un numero corretto..\n");
					dayCorrect = 0;
				}
			}
			while (dayCorrect == 0);
		}
		while (day != 0);

	}



	printf("\nI giorni liberi in comune sono i seguenti: ");
	for (i = 1; i <= monthLen; i++)
	{
		if (user1[i] == user2[i] && user1[i] == 1)
		{
			printf("%d ", i+1);
			j++;
		}
	}

	//se non ci sono giorni in comune stampa null
	if (j == 0)
	{
		printf("/// \n Non ci sono giorni liberi in comune.");
	}
	puts("\n\n");
	return 0;
}
