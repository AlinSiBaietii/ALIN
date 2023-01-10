#ifndef FUNCTII_H // pentru a preveni copierea de mai multe ori a fisierului header
#define FUNCTII_H // pentru a preveni copierea de mai multe ori a fisierului header

#include <stdio.h> // pentru functiile scanf/printf
#include <stdlib.h> // pentru malloc/free
#include <string.h> // pentru strcpy

struct NOD {
    char nr_inmatriculare[8];
    struct NOD * next;
};

// Functionalitate cozi:
// 1. enqueue (adaugare element pe ultima pozitie)
// 2. dequeue (stergerea elementului de pe prima pozitie)
// 3. peek (accesarea datelor utile din primul element)

// 4. afisarea elementelor din lista

struct NOD * creare_nod(char nr_inmatriculare[8]);
struct NOD * enqueue(struct NOD * head, char nr_inmatriculare[8]);
struct NOD * dequeue(struct NOD *);
char * peek(struct NOD * head);
void afisare(struct NOD * head);

#endif // pentru a preveni copierea de mai multe ori a fisierului header