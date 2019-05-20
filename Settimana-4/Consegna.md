# Settimana 4
# Esercizio 1
Scrivere un programma C che generi un “cammino casuale” all’interno di una matrice 10x10. La matrice conterrà dei caratteri (inizialmente saranno tutti ‘.’). Il programma deve passare casualmente da un elemento all'altro, muovendosi in alto, in basso, a sinistra o a destra di una posizione soltanto. Gli elementi visitati dal programma dovranno essere etichettati con lettere che vanno dalla A alla Z nell'ordine con cui vengono visitati. Ecco un esempio dell’output desiderato:

A . . . . . . . . . .

B C D . . . . . . .

. F E . . . . . . .

H G . . . . . . . .

I . . . . . . . . .

J . . . . . . . Z .

K . . R S T U V Y .

L M P Q . . . W X .

. N O . . . . . . .

. . . . . . . . . .

Suggerimento: generare un numero casual fra 0 e 3 indicante la direzione della prossima mossa. Prima di effettuare la mossa controllare che:

Non vada fuori dalla matrice
Non porti ad un elemento al quale è già stata assegnata una lettera.
Se una delle due condizioni viene violata, provate a muovervi in un’altra direzione. Se tutte le direzioni sono bloccate, il programma deve terminare. Ecco un esempio di fine prematura:

A B G H I . . . . .
. C F . J K . . . .
. D E . M L . . . .
. . . . N O . . . .
. . W X Y P Q . . .
. . V U T S R . . .
. . . . . . . . . .
. . . . . . . . . .
. . . . . . . . . .
. . . . . . . . . .

Y è bloccata in tutte le direzioni quindi non c’è modo di inserire Z.

# Esercizio 2
Scrivere un programma C che riceva in ingresso due parole inserite da tastiera. Si consideri che ciascuna parola può contenere al massimo 30 caratteri. Il programma deve essere case sensitive, cioè deve distinguere lettere minuscole da lettere maiuscole e deve essere in grado anche di analizzare numeri, simboli e segni di punteggiatura.

Il programma deve sostituire ogni occorrenza della seconda parola nella prima parola con il carattere '\*'. Ad esempio, inserite le parole

abchdfffchdchdtlchd

e

chd

il programma deve visualizzare la parola

ab*fff**tl*

Scrivere due versioni: la prima deve ignorare la presenza della libreria string.h e quindi dovete lavorare esplicitamente su ogni singolo carattere delle stringhe. La seconda deve usare le funzioni della libreria string.h per determinare la lunghezza e per ricercare sotto-stringhe all'interno di una stringa
