struct StructLibro {
	char* codice;
	char* titolo;
	char* autore;
	int anno;
	char* editore;
	int lunghezza;
	char* genere;
	int valutazione;
	int numero;
	struct StructLibro *next;
};

typedef struct StructLibro Libro;
typedef Libro *Listalibri;
char *input_stringa();
int Empty(Listalibri * l);
void Aggiungi_libro(Listalibri * l,int n);
void Cancella_libro(Listalibri * l,char *codice);
void stato_libri(Listalibri *l,int n);
void stato_libri_val(Listalibri *l, int valutazione);
