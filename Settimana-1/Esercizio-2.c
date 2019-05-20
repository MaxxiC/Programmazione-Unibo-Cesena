#include <stdio.h>
#include <stdlib.h>

int main()
{
	//variabile
	int a, b, risultato;
	a = 20;
	b = 5;


	printf("Operatori Aritmetici\n");

	//Stampo il loro contenuto
	printf("Le variabili valgono: a= %d e b= %d\n", a, b);
	//Effettuo la somma
	risultato = a + b;
	//Stampo il risultato finale
	printf("La somma e' = %d\n\n", a, b, risultato);

	//Sottrazione
	printf("Le variabili valgono: a= %d e b= %d\n", a, b);
	risultato = a - b;
	printf("La sottrazione e' = %d\n\n", a, b, risultato);

	//moltiplicazione
	printf("Le variabili valgono: a= %d e b= %d\n", a, b);
	risultato = a * b;
	printf("La moltiplicazione e' = %d\n\n", a, b, risultato);

	//divisione
	printf("Le variabili valgono: a= %d e b= %d\n", a, b);
	risultato = a / b;
	printf("La divisione e' = %d\n\n", a, b, risultato);

	//resto della divisione
	printf("Le variabili valgono: a= %d e b= %d\n", a, b);
	risultato = a % b;
	printf("Il resto della divisione e' = %d\n\n", a, b, risultato);


	printf("\n\n\n");


	printf("Operatore ++\n");
	printf("Le variabili a ora vale %d \n", a);

	printf("con l'operatore ++[var] o simile [var]++ incrementiamo di 1 la variabile stessa\n");
	//eseguo l'operatore ++
	a++;
	printf("dopo l'esecuzione il suo valore e' %d\n", a, b);


	printf("\n");


	printf("Operatore --\n");
	printf("La variabile b ora vale %d\n", b);
	printf("con l'operatore --[var] o simile [var]-- diminuiamo di 1 la variabile stessa\n");
	//effettuo l'operazione --
	b--;
	printf("dopo l'esecuzione il suo valore e' %d\n", b);


	printf("\n\n\n");


	//operatore +=
	printf("Operatore compatto +=\n");
	a = 7;
	printf("La variabile a inizialmente vale %d",a);
	printf(" se esegui  a += a il risultato sara' %d \n", a+=a);

	printf("\n");

	//operatore -=
	printf("Operatore compatto -=\n");
	a = 12;
	printf("La variabile a inizialmente vale %d", a);
	printf(" se esegui  a -= a il risultato sara' %d \n", a -= a);

	printf("\n");

	//operatore /=
	printf("Operatore compatto /=\n");
	a = 12;
	printf("La variabile a inizialmente vale %d", a);
	printf(" se esegui  a /= a il risultato sara' %d \n", a /= a);

	printf("\n");

	//operatore *=
	printf("Operatore compatto *=\n");
	a = 12;
	printf("La variabile a inizialmente vale %d", a);
	printf(" se esegui  a *= a il risultato sara' %d \n", a *= a);

	printf("\n");

	//operatore %=
	printf("Operatore compatto %%=\n");
	a = 12;
	printf("La variabile a inizialmente vale %d", a);
	printf(" se esegui  a %%= a il risultato sara' %d \n", a %= a);

	system("PAUSE");
	return 0;
}