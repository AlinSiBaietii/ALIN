#include "functii.h"

struct NOD * creare_nod(char nr_inmatriculare[8]){
    struct NOD * nod_nou = malloc(sizeof(struct NOD));
    // strcpy(dest, src);
    strcpy(nod_nou -> nr_inmatriculare, nr_inmatriculare);
    nod_nou -> next = NULL;
    return nod_nou;
}

// enqueue - adauga un element pe ultima pozitie
struct NOD * enqueue(struct NOD * head, char nr_inmatriculare[8]){
    // 1. verificam daca lista e goala
    // da: cream un nod, il facem head si il returnam
    // nu:
    // 2. parcurgem coada cu un pointer (ptr) pana la ultimul element (ptr->next == NULL)
    // 3. cream un nod nou (nod_nou)
    // 4. legam ultimul nod de noul nod (ptr->next = nod_nou)
    // 5. returnam head
    
    // 1:
    if (head == NULL){
        head = creare_nod(nr_inmatriculare);
        return head;
    }
    
    // 2:
    struct NOD * ptr = NULL;
    ptr = head;
    while (ptr->next != NULL){
        ptr = ptr -> next;
    }
    
    // 3:
    struct NOD * nod_nou = creare_nod(nr_inmatriculare);
    
    // 4:
    ptr -> next = nod_nou;
    
    // 5:
    return head;
}

// dequeue - stergerea elementului de pe prima pozitie
struct NOD * dequeue(struct NOD * head){
    // 1. retinem pointer catre primul element (ptr_first)
    // 2. mutam head pe pozitia a doua
    // 3. stergem primul element cu functia free(ptr_first)
    // 4. returnam head
    
    // 1:
    struct NOD * ptr_first = head;
    
    // 2:
    head = head -> next;
    
    // 3:
    free(ptr_first);
    
    // 4:
    return head;
}

char * peek(struct NOD * head){
    return head -> nr_inmatriculare;
}

void afisare(struct NOD * head){
    while (head != NULL){
        printf("%s\n", head -> nr_inmatriculare);
        head = head -> next;
    }
}