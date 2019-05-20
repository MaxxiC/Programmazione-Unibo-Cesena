# Settimana 8
# Esercizio 1
Si scriva un programma C, adeguatamente commentato, che gestisca un certo numero di studenti iscritti ad un corso di laurea. Il programma utilizza un vettore di strutture, ognuna delle quali memorizza le informazioni di uno studente (numero matricola, nome e cognome, anno di immatricolazione, piano di studi). Il programma deve fornire la possibilità di:

aggiungere un nuovo studente, stampando un messaggio di errore se lo studente è già presente (individuato dalla matricola) o se il vettore è pieno.
dato il numero di matricola, stampare le informazioni dello studente oppure un messaggio di errore se la matricola non è presente nel vettore
dato un numero di matricola, modificare le informazioni del piano di studi aggiungendo un voto oppure stampando un messaggio di errore se la matricola non è presente nel vettore.
Il piano di studi è un vettore di NUM_ESAMI elementi ognuno di tipo struttura contenete il nome dell'insegnamento e il voto corrispondente (0 se non sostenuto).

# Esercizio 2
Modificare il programma dell'esercizio 1 in modo che il vettore di studenti venga allocato dinamicamente e successivamente riallocato al suo riempimento. Inizialmente usare la funzione malloc() per allocare lo spazio sufficiente per un vettore di 10 strutture studente, Quando il vettore non ha più spazio per contenere nuovi studenti, utilizzare la funzione realloc() per raddoppiare la sua dimensione. Ripetere il raddoppio delle dimensioni ogni volta che il vettore si riempe.
