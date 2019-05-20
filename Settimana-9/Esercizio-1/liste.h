#define N 10
typedef int TipoElemLista;
typedef int* TipoElemListaD;
struct StructLista {
	TipoElemLista info[N];
	int last; //mantiene la posizione dell’ultimo elemento della lista
			  //all’interno del vettore
};
typedef struct StructLista TipoLista;
struct StructListaD {
	TipoElemListaD info;
	int last;
};
typedef struct StructListaD TipoListaD;
struct StructListaCollegata {
	TipoElemLista info;
	struct StructListaCollegata *next;
	int last;
};
typedef struct StructListaCollegata TipoListaC;
typedef TipoListaC *ListaCollegata;

int Full(TipoLista *l);
int Empty(TipoLista *l);
int EmptyD(TipoListaD *l);
int EmptyC(ListaCollegata*l);
void Inserisci_dopo_elem(TipoLista *l, int index, TipoElemLista x);
void Cancella_testa(TipoLista * l);
void Cancella_coda(TipoLista * l);
void Cancella_n(TipoLista *l, TipoElemLista x);
void Inserisci_testa(TipoLista *l, TipoElemLista x);
void Inserisci_coda(TipoLista *l, TipoElemLista x);
void prt_err(TipoLista *l);
void resize_lista(TipoElemListaD *l, int last);
void stato_lista(TipoLista *l);
void Inserisci_dopo_elemD(TipoListaD *l, int index, TipoElemLista x);
void Cancella_testaD(TipoListaD * l);
void Cancella_codaD(TipoListaD * l);
void Cancella_nD(TipoListaD *l, TipoElemLista x);
void Inserisci_testaD(TipoListaD *l, TipoElemLista x);
void Inserisci_codaD(TipoListaD *l, TipoElemLista x);
void prt_errD(TipoListaD *l);
void stato_listaD(TipoListaD *l);
void Aggiungi_testaC(ListaCollegata *l, TipoElemLista x);
void Aggiungi_codaC(ListaCollegata *l, TipoElemLista x);
void Aggiungi_dopo_elemC(ListaCollegata *l, int index, TipoElemLista x);
void Cancella_testaC(ListaCollegata *l);
void Cancella_codaC(ListaCollegata *l);
void Cancella_elemC(ListaCollegata *l, TipoElemLista x);
void stato_listaC(ListaCollegata *l);
