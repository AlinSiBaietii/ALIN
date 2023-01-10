#include <stdlib.h>
#include <stdio.h>
#include <string.h>



//Rezolvam problema cu lista

//Definim Lista
struct NOD {

    int valoare;
    struct NOD * next;

};



//Functii care ne vor ajuta in rezolvare

//Functia pentru creare nod
struct NOD * creare_nod(int x){
    struct NOD * nod;

    //Alocarea memorie NOD
    nod = (struct NOD * ) malloc(sizeof(struct NOD));


    //Conditia pentru lista goala
    if (nod == NULL) {
        //Memoria nu a putut fi alocata
        return NULL;
    }

    //Citirea valori NOD
    nod->valoare = x;
    nod->next = NULL;

    return nod;
}


//Functia pentru adaugare NOD la sfarsitul listei
struct NOD * adaugare_nod_sfarsit_lista(struct NOD * head, int x) {
    int i = 0;
    struct NOD * nod_curent, * nod_nou;

    //Daca este goala o sa se adauge la inceput
    if (head == NULL) {
        //Lista Goala
        head = creare_nod(x);
        //Valoarea adaugata
        return head;
    }

    //Parcurgere lista element cu element pentru a ajunge la ultimul NOD
    nod_curent = head;

    while (nod_curent != NULL) {
        if (nod_curent -> next == NULL) {
            //Creare si inserare nod nou in lista
            nod_nou = creare_nod(x);
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
        printf("%d ", nod_curent -> valoare);
        nod_curent = nod_curent -> next;
    }
}


//Functia pentru cardinal / lungime lista
int cardinal(struct NOD * head){

    int count = 0;
    while (head != NULL){
        count++;
        head = head -> next;
    }
    return count;

}



//Functia pentru verificare element in lista
int is_element_of(int x, struct NOD * head){

    while (head != NULL){
        if (head -> valoare == x){
            return 1;
        }
        head = head -> next;
    }
    return 0;
}


//REZOLVARE CERINTA

//Functia pentru elemente comune
void intersect(struct NOD * lista_interval, struct NOD * lista_mare){

    struct NOD * lista_finala = NULL;

    int contor = 0;         //contor pentru valori


    while(lista_interval != NULL){


        //Daca ESTE element al listei MARE INCREMENTAM  0-FALSE 1-TRUE
        if(is_element_of(lista_interval->valoare, lista_mare) == 1){

                contor = contor+1;

        }

        lista_interval = lista_interval->next;


    }


    //Conditie rezultat
    printf("%d", contor);



}

//Functia main care rezolva problema
int main(){

    struct NOD * lista_mare = NULL;             //lista cu multe nr care se repeta
    struct NOD * lista_interval = NULL;         //lista cu intervalul fara sa se repete

    int n;          //numarul pana unde se afla intervalul

    int x;          //valoare pentru lista mare
    int y;          //valoare pentru interval


    //Citim intervalul [0,n]
    scanf("%d", &n);


    //LISTA MARE

    int z = 2*n; //un contor sa avem un numar de valori in lista

    do{
        //Citim numarul de la tastatura
        scanf("%d", &x);

        //Adaugam elementul in lista
        lista_mare = adaugare_nod_sfarsit_lista(lista_mare,x);

        z=z-1;

    }while(z>0);





    //LISTA INTERVAL

    y=0;    //incepem de la 0 pana la n

    do{

        //Il punem pe y in lista
        lista_interval =  adaugare_nod_sfarsit_lista(lista_interval,y);

        //Incrementam elementul 0...1...2...3...n
        y = y+1;

    }while(y<=n);

    //Afisare liste
    afisare_lista(lista_mare);
    printf("\n");
    afisare_lista(lista_interval);
    printf("\n");


    //AFISARE REZULTAT
    //Comparam intervalul cu lista mare
    intersect(lista_interval,lista_mare);







    return 0;

}
