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



//Functia pentru afisare elemente lista IN ORDINE CRESCATOARE
void afisare_lista_in_ordine(struct NOD * head){
    int i = 0;
    struct NOD * nod_curent;
    struct NOD * index;

    int temp;               //Variabila de lucru

    //Conditia pentru lista goala
    if (head == NULL) {
        //Lista Goala
        return;
    }

    nod_curent = head;


    //Ordonare Valori
    while (nod_curent != NULL) {

        index = nod_curent->next;

            while(index != NULL){

                //Daca e mai mare sortam valorile
                if(nod_curent->valoare > index->valoare){

                    temp = nod_curent->valoare;
                    nod_curent->valoare = index->valoare;
                    index->valoare = temp;

                }

                index = index->next;

            }

        nod_curent = nod_curent->next;

    }

    //Afisam lista sortata
    afisare_lista(head);

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
void intersect(struct NOD * lista_bunica, struct NOD * lista_bingo){

    struct NOD * lista_finala = NULL;

    int cardinal_1 = cardinal(lista_bunica);
    int cardinal_2 = cardinal(lista_bingo);


    while(lista_bunica != NULL){


        //Daca NU este element al listei il punem in lista noua  0-FALSE 1-TRUE
        if(is_element_of(lista_bunica->valoare, lista_bingo) == 0){
            lista_finala = adaugare_nod_sfarsit_lista(lista_finala,lista_bunica->valoare);
        }

        lista_bunica = lista_bunica->next;


    }


    //Conditie rezultat
    int cardinal_3 = cardinal(lista_finala);

    if(cardinal_3 == 0){
        printf("BINGO!");
    }

    else
        afisare_lista_in_ordine(lista_finala);


}



//Functia main care rezolva problema
int main(){

    struct NOD * lista_bunica = NULL;
    struct NOD * lista_bingo = NULL;
    struct NOD * conditie_bingo = NULL;

    int n;                      //dimensiune n x n matrice

    int b;                      //valoarea pentru lista bunicii
    int numar_elemente_bunica;  //numar elemente lista bunicii
    int x;                      //valoare pentru lista strigata


    //LISTA BUNICA

    //Citim dimensiunea listei bunicii
    scanf("%d", &n);

    //Elementele listei bunicii
    numar_elemente_bunica = n*n;

    do{

        //Scanam elementul din lista bunicii
        scanf("%d", &b);

        //Il punem in lista
        lista_bunica =  adaugare_nod_sfarsit_lista(lista_bunica,b);

        numar_elemente_bunica = numar_elemente_bunica-1;

    }while(numar_elemente_bunica>=1);



    //LISTA STRIGATA

    //Elementele listei STRIGATE


    //Citim pana la End of File
    while(scanf("%d", &x) != EOF){

        //Adaugam elementul in lista
        lista_bingo = adaugare_nod_sfarsit_lista(lista_bingo,x);


    }


    //AFISARE REZULTAT
    intersect(lista_bunica, lista_bingo);



    return 0;





}
