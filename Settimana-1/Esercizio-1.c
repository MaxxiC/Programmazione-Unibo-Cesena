#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

int main()
{
	//dichiarazione delle variabili
	
	int n_caratteri;	// n caratteri stampati dalla printf 

	int intero = 12;
	unsigned int _intero_no_segno = 11;
	short int _intero_corto = 5;
	unsigned short int _intero_no_segno_corto = 4;
	long int _intero_lungo = 1234;
	unsigned long int _intero_lungo_no_segno = 15328;
	char carattere = 'a';
	unsigned char carattere_no_segno = 'b';
	float _float_ = 4.2;
	double _double_ = 4.254;
	long double _long_double_ = 44.5;


	//variabile intera, utilizzo i %d per stamapre
	n_caratteri = printf(" Tipo : %-9s Min : %-20d Max : %-20d Bytes : %d\n ", " int ", INT_MIN, INT_MAX, sizeof(int));
	printf("Numero Caratteri Stampati :%d		Valore Variabile: %d\n\n\n", n_caratteri, intero);


	//unsigned int , utilizzo %u per specificare che è un tipo unsigned
	n_caratteri = printf(" Type : %-9s Min : %-20d Max : %-20u Bytes : %d\n ", " unsigned_int ", 0, UINT_MAX, sizeof(unsigned int));
	printf("Numero Caratteri Stampati :%d		Valore Variabile: %d\n\n\n", n_caratteri, _intero_no_segno);


	//short int, utilizzo %d
	n_caratteri = printf(" Type : %-9s Min : %-20d Max : %-20d Bytes : %d\n ", " short_int ", SHRT_MIN, SHRT_MAX, sizeof(short int));
	printf("Numero Caratteri Stampati :%d		Valore Variabile: %d\n\n\n", n_caratteri, _intero_no_segno);


	//unsigned short int, utilizzo il %u
	n_caratteri = printf(" Type : %-9s Min : %-20d Max : %-20u Bytes : %d\n ", " unsigned short int ", 0, USHRT_MAX, sizeof(unsigned short int));
	printf("Numero Caratteri Stampati :%d		Valore Variabile: %d\n\n\n", n_caratteri, _intero_no_segno_corto);


	//long int, utilizzo il %ld per specificare che è un tipo long
	n_caratteri = printf(" Type : %-9s Min : %-20ld Max : %-20ld Bytes : %d\n ", " long int ", LONG_MIN, LONG_MAX, sizeof(long int));
	printf("Numero Caratteri Stampati :%d		Valore Variabile: %d\n\n\n", n_caratteri, _intero_lungo);


	//unsigned long int, il %lu specifica l'utilizzo di una variabile unsigned long
	n_caratteri = printf(" Type : %-9s Min : %-20lu Max : %-20lu Bytes : %d\n ", " unsigned long int ", 0, ULONG_MAX, sizeof(unsigned long int));
	printf("Numero Caratteri Stampati :%d		Valore Variabile: %d\n\n\n", n_caratteri, _intero_lungo_no_segno);


	//char, stampo i valori %d e la variabile stessa con %c
	n_caratteri = printf(" Type : %-9s Min : %-20d Max : %-20d Bytes : %d\n ", " char ", CHAR_MIN, CHAR_MAX, sizeof(char));
	printf("Numero Caratteri Stampati :%d		Valore Variabile: %c\n\n\n", n_caratteri, carattere);


	//unsigned char
	n_caratteri = printf(" Type : %-9s Min : %-20d Max : %-20d Bytes : %d\n ", " unsigned char ", 0, UCHAR_MAX, sizeof(unsigned char));
	printf("Numero Caratteri Stampati :%d		Valore Variabile: %c\n\n\n", n_caratteri, carattere_no_segno);


	//float, utilizzo il %f
	n_caratteri = printf(" Type : %-9s Min : %-20e Max : %-20e Bytes : %d\n ", " float ", FLT_MIN, FLT_MAX, sizeof(float));
	printf("Numero Caratteri Stampati :%d		Valore Variabile: %.2f\n\n\n", n_caratteri, _float_);


	//double
	n_caratteri = printf(" Type : %-9s Min : %-20g Max : %-20g Bytes : %d\n ", " double ", DBL_MIN, DBL_MAX, sizeof(double));
	printf("Numero Caratteri Stampati :%d		Valore Variabile: %.3lf\n\n\n", n_caratteri, _double_);


	//long double
	n_caratteri = printf(" Type : %-9s Min : %-20g Max : %-20g Bytes : %d\n ", " long double ", LDBL_MIN, LDBL_MAX, sizeof(long double));
	printf("Numero Caratteri Stampati :%d		Valore Variabile: %Lf\n\n\n", n_caratteri, _long_double_);

	system("PAUSE");
	return 0;

}