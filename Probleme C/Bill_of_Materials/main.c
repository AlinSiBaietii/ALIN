#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//Rezolvam problema cu lista

//Definim Lista
struct NOD {

    char item[256];
    struct NOD * next;

};




//Functii care ne vor ajuta in rezolvare

//Functia pentru creare nod
struct NOD * creare_nod(char item[]){
    struct NOD * nod;

    //Alocarea memorie NOD
    nod = (struct NOD * ) malloc(sizeof(struct NOD));


    //Conditia pentru lista goala
    if (nod == NULL) {
        //Memoria nu a putut fi alocata
        return NULL;
    }


    //Citirea valori NOD
    strcpy(nod->item, item);
    nod->next = NULL;

    return nod;
}

//Functia pentru adaugare NOD la sfarsitul listei
struct NOD * adaugare_nod_sfarsit_lista(struct NOD * head, char item[]) {
    int i = 0;
    struct NOD * nod_curent, * nod_nou;

    //Daca este goala o sa se adauge la inceput
    if (head == NULL) {
        //Lista Goala
        head = creare_nod(item);
        //Valoarea adaugata
        return head;
    }

    //Parcurgere lista element cu element pentru a ajunge la ultimul NOD
    nod_curent = head;

    while (nod_curent != NULL) {
        if (nod_curent -> next == NULL) {
            //Creare si inserare nod nou in lista
            nod_nou = creare_nod(item);
            nod_curent -> next = nod_nou;

            //Am adaugat valoarea
            return head;
        }
        nod_curent = nod_curent -> next;
    }
}


//Functia pentru afisare elemente lista
void afisare_lista(struct NOD * head){

    int i = 0;
    struct NOD * nod_curent;

    //Conditia pentru lista goala
    if (head == NULL) {
        //Lista Goala
        return;
    }

    nod_curent = head;

    while (nod_curent != NULL) {
        //Afisarea valoarea curenta si mutarea pe nodul urmator
        printf("%s ", nod_curent -> item);
        nod_curent = nod_curent -> next;
    }
}


//Functia pentru verificare element in lista
int is_element_of(char item[], struct NOD * head){

    while (head != NULL){
        //Cand comparam STRING
        if (strcmp(head->item,item) == 1){
            return 1;
        }
        head = head -> next;
    }
    return 0;
}


//REZOLVARE CERINTA

//Functia pentru elemente comune
void intersect(struct NOD * lista_cumparaturi, struct NOD * lista_catalog){

    struct NOD * lista_finala = NULL;

    int contor = 0;         //contor pentru iteme comune din ambele liste

    while(lista_cumparaturi != NULL){


        //Daca ESTE element al listei INCREMENTAM  0-FALSE 1-TRUE
        //Ce este in IF inseamna ca este 1-TRUE
        if(is_element_of(lista_cumparaturi->item, lista_catalog) == 1){

            contor = contor+1;

        }

        lista_cumparaturi = lista_cumparaturi->next;


    }


    //Conditie rezultat
    printf("%d", contor);



}

//Functia main care ne rezolva problema
int main(){

    struct NOD * lista_cumparaturi = NULL;
    struct NOD * lista_catalog = NULL;

    char element_lista_cumparaturi[256];
    char element_lista_catalog[256];
    int n;                                  //numar elemente lista cumparaturi


    //LISTA CUMPARATURI

    //Citim de la tastatura numarul de elemente din lista de cumparaturi
    scanf("%d", &n);

    //Punem elementele in lista_cumparaturi
    do{

        //Scanam elementul din lista de cumparaturi
        scanf("%s", element_lista_cumparaturi);

        lista_cumparaturi = adaugare_nod_sfarsit_lista(lista_cumparaturi, element_lista_cumparaturi);

        n = n-1;

    }while(n>=1);



    //LISTA CATALOG

    //Citim pana la End of File
    while(scanf("%s", element_lista_catalog) != EOF){

        //Adaugam elementul in lista
        lista_catalog = adaugare_nod_sfarsit_lista(lista_catalog, element_lista_catalog);


    }


    //AFISARE REZULTAT
    intersect(lista_cumparaturi, lista_catalog);



    return 0;



}
