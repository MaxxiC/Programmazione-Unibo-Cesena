#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define mlung 30


int main(void)
{
	//stringa iniziale (D)
	char ch = (char*)malloc((1) * sizeof(char));
	char *pch;//puntatore al carattere
	char *ppch;//punatore al puntatore
	pch = (char*)malloc((mlung + 1) * sizeof(char));//creazione spazio per stringa
	ppch = pch;//inizializzo al primo posto il puntatore del puntatore

	//stringa punto B
	char ch2 = (char*)malloc((1) * sizeof(char));
	char *pch2;
	char *ppch2;
	pch2 = (char*)malloc((mlung + 1) * sizeof(char));
	ppch2 = pch2;

	//stringa punto C
	char ch3 = (char*)malloc((1) * sizeof(char));
	char *pch3;
	char *ppch3;
	pch3 = (char*)malloc((mlung + 1) * sizeof(char));
	ppch3 = pch3;

	int j = 0;



	printf("A) Inserisci la frase della canzone da modificare: ");

	//////////////////////////////////////////////////////////////////////////////////////////////////
	//Punto B
	//controllo i caratteri fino a quando non trovo un \n (a capo)
	while ((ch = getchar()) != '\n')
	{
		*pch = ch;//trasformo tutti i caratteri in maiuscolo
		pch++;//scorro la posizone del puntatore

		switch (ch)
		{
		case '\x85':
			*pch2 = '\xB7';
			pch2++;
			j++;
			break;
		case '\x8A':
			*pch2 = '\xD4';
			pch2++;
			j++;
			break;
		case '\x8D':
			*pch2 = '\xD6';
			pch2++;
			j++;
			break;
		case '\x95':
			*pch2 = '\xE3';
			pch2++;
			j++;
			break;
		case '\x97':
			*pch2 = '\xEB';
			pch2++;
			j++;
			break;
		default:
			if (!isdigit(ch))//controllo per spazi e segni di punteggiatura e numeri
			{
				*pch2 = toupper(ch);
				pch2++;
				j++;
			}
			break;
		}

	}
	*pch = '\0';//inserisco carattere di terminazione
	*pch2 = '\0';

	printf("\n--rimozione dei numeri");
	printf("\nB) Trasformazione in maiuscolo = %s\n", ppch2);


	///////////////////////////////////////////////////////////////////////////////////////////////
	//Punto C
	for (int i = 0; i < j; i++)
	{
		ch = ppch2[i];


		switch (ch)
		{
		case '\xB7':
			*pch3 = ch;
			pch3++;
			break;
		case '\xD4':
			*pch3 = ch;
			pch3++;
			break;
		case '\xD6':
			*pch3 = ch;
			pch3++;
			break;
		case '\xE3':
			*pch3 = ch;
			pch3++;
			break;
		case '\xEB':
			*pch3 = ch;
			pch3++;
			break;
		default:
			if (!isspace(ch) && !ispunct(ch))//controllo per spazi e segni di punteggiatura
			{
				*pch3 = ch;
				pch3++;
			}
			break;
		}




	}
	*pch3 = '\0';

	//system("cls");
	printf("C) Rimozione spazi e punteggitura = %s\n", ppch3);
	printf("D) Ri-visualizzazione a monitor = %s\n\n", ppch);

	system("pause");
	return 0;
}