#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// multimea <-> set are mai multe caracteristici:
// 1. toate elementele sunt de acelasi tip
// 2. fiecare element apare o singura data / este unic
// 3. nu conteaza ordinea elementelor

// Posibile implementari pentru multime:
// 1. lista simplu inlantuita <-> singly linked list
// 2. arbore binar de cautare <-> binary search tree (BST)
// 3. (optional) hashtree
// 4. (optional) hashset

// Multimile au o serie de functionalitati:
// 1. -
// 2. afisarea elementelor
// 3. gasirea numarului de elemente dintr-o multime / cardinalul multimii
// 4. verificarea daca un element face parte dintr-o multime
// 5. adaugarea unui element la multime
// 6. stergerea unui element dintr-o multime
// 7. verificare daca o multime este vida sau nu


// Algebra multimilor
// 1. reuniuni
// 2. intersectii
// 3. diferenta
// 4. incluziuni <-> aflarea submultimilor
// 5. diferenta simetrica <-> reuniunea diferentelor (A-B, B-A) dintre 2 multimi
// 6. produsul cartezian


//Definim Lista
struct nod {
    int val;
    struct nod * next;
};


//Functia pentru creare nod
struct nod * create_node(int x){
    struct nod * new_node = NULL;

    new_node = malloc(sizeof(struct nod));

    if (new_node == NULL){
        return NULL;
    }

    new_node -> val = x;
    new_node -> next = NULL;

    return new_node;
}


//Functia pentru verificare daca un element este in lista
int is_element_of(int x, struct nod * head){
    while (head != NULL){
        if (head -> val == x){
            return 1;
        }
        head = head -> next;
    }
    return 0;
}


//Functia pentru adaugare element in lista
struct nod * add_element_to_set(int x, struct nod * head){
    struct nod * new_node = NULL;

    // Verificam daca elementul x exista deja in multime
    if (is_element_of(x, head)){
        return head;
    }

    if (head == NULL){
        return create_node(x);
    }

    new_node = create_node(x);
    new_node -> next = head;

    return new_node;
}



//Functia pentru afisare
void display(struct nod * head){
    while (head != NULL){
        printf("%d ", head -> val);
        head = head -> next;
    }
}


//Functia pentru cardinal / lungime lista
int cardinal(struct nod * head){
    int count = 0;
    while (head != NULL){
        count++;
        head = head -> next;
    }
    return count;
}


//Functia pentru eliminare element
struct nod * remove_element(int x, struct nod * head){
    struct nod * temp = NULL;
    struct nod * to_be_erased = NULL;

    if (!is_element_of(x, head)){
        return head;
    }

    if (head == NULL){
        printf("Set is already empty.\n");
        return NULL;
    }

    // 3 situatii
    // 1. stergerea primului element
    // 2. stergerea unui element intermediar
    // 3. stergerea ultimului element

    // Stergerea primului element:
    if (x == head -> val){
        temp = head;            // retinem referinta catre primul element din lista
        head = head -> next;    // mutam inceputul listei pe a doua pozitie
        free(temp);             // stergem primul element din lista
        temp = NULL;            // pentru a evita situatia "dangling pointer"
        return head;            // returnam referinta noului prim nod din lista
    }

    // Stergerea unui element intermediar sau a ultimului nod
    temp = head;
    // Ne pozitionam pe elementul predecesor nodului care are valoarea x
    while ((temp -> next -> val != x) && (temp -> next != NULL)){
        temp = temp -> next;
    }
    to_be_erased = temp -> next;
    temp -> next = to_be_erased -> next;
    free (to_be_erased);
    to_be_erased = NULL;
    return head;

}


//Functia pentru verficiare lista goala
int set_is_empty(struct nod * head){
    if (head == NULL){
        return 1;
    }
    return 0;
}


//Functia pentru toate elementele
struct nod * reuniune(struct nod * head_set_1, struct nod * head_set_2){
    struct nod * head_set_3 = NULL;

    while (head_set_1 != NULL){
        head_set_3 = add_element_to_set(head_set_1 -> val, head_set_3);
        head_set_1 = head_set_1 -> next;
    }

    while (head_set_2 != NULL){
        head_set_3 = add_element_to_set(head_set_2 -> val, head_set_3);
        head_set_2 = head_set_2 -> next;
    }

    return head_set_3;
}


//Functia pentru elementele din set_1 care sunt si in set_2
struct nod * intersect(struct nod * head_set_1, struct nod * head_set_2){
    struct nod * head_set_3 = NULL;

    int card_1 = cardinal(head_set_1);
    int card_2 = cardinal(head_set_2);

    if (card_1 < card_2){
        for (int i = 0; i < card_1; i++){

            if (is_element_of(head_set_1 -> val, head_set_2)){
                head_set_3 = add_element_to_set(head_set_1 -> val, head_set_3);
            }
            head_set_1 = head_set_1 -> next;
        }
    } else {
        for (int j = 0; j < card_2; j++){
            if (is_element_of(head_set_2 -> val, head_set_1)){
                head_set_3 = add_element_to_set(head_set_2 -> val, head_set_3);
            }
            head_set_2 = head_set_2 -> next;
        }
    }

    return head_set_3;
}




//Functia main care ne rezolva problema
int main()
{
    struct nod * set_1 = NULL;
    struct nod * set_2 = NULL;
    struct nod * set_3 = NULL;
    struct nod * set_4 = NULL;

    set_1 = add_element_to_set(10, set_1);
    set_1 = add_element_to_set(2, set_1);
    set_1 = add_element_to_set(1, set_1);
    set_1 = add_element_to_set(7, set_1);
    set_1 = add_element_to_set(5, set_1);

    printf("Afisare elemente multime A:\n");
    display(set_1);

    set_2 = add_element_to_set(10, set_2);
    set_2 = add_element_to_set(2, set_2);
    set_2 = add_element_to_set(1, set_2);
    set_2 = add_element_to_set(8, set_2);
    set_2 = add_element_to_set(6, set_2);

    printf("\nAfisare elemente multime B:\n");
    display(set_2);

    printf("\nAfisare reuniune A U B:\n");
    set_3 = reuniune(set_1, set_2);
    display(set_3);

    printf("\nAfisare intersectie A si B:\n");
    set_4 = intersect(set_1, set_2);
    display(set_4);

    return 0;
}
