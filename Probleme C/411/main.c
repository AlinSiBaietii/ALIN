#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//O rezolvam cu LISTE


//Definim Lista
struct NOD {

    char nume[256];          //numele persoane
    int cantitate;          //numarul de produse
    int pret;               //pretul produsului
    struct NOD * next;

};


//Functii care ne vor ajuta in rezolvare

//Functia pentru creare nod
struct NOD * creare_nod(char nume[], int cantitate, int pret){
    struct NOD * nod;

    //Alocarea memorie NOD
    nod = (struct NOD * ) malloc(sizeof(struct NOD));


    //Conditia pentru lista goala
    if (nod == NULL) {
        //Memoria nu a putut fi alocata
        return NULL;
    }

    //Citirea valori NOD
    strcpy(nod->nume, nume);
    nod->cantitate = cantitate;
    nod->pret = pret;

    nod->next = NULL;

    return nod;
}


//Functia pentru adaugare NOD la sfarsitul listei
struct NOD * adaugare_nod_sfarsit_lista(struct NOD * head, char nume[], int cantitate, int pret) {
    int i = 0;
    struct NOD * nod_curent, * nod_nou;

    //Daca este goala o sa se adauge la inceput
    if (head == NULL) {
        //Lista Goala
        head = creare_nod(nume, cantitate, pret);
        //Valoarea adaugata
        return head;
    }

    //Parcurgere lista element cu element pentru a ajunge la ultimul NOD
    nod_curent = head;

    while (nod_curent != NULL) {
        if (nod_curent -> next == NULL) {
            //Creare si inserare nod nou in lista
            nod_nou = creare_nod(nume, cantitate, pret);
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
        printf("%s %d %d\n",    nod_curent -> nume,
                                nod_curent -> cantitate,
                                nod_curent -> pret);

        nod_curent = nod_curent -> next;
    }

}

//OPTIUNEA 1

//Functia pentru optiunea 1 de afisare
void afisare_lista_V1(struct NOD * head){

    int i = 0;
    int produs=0;     //cantitate x pret
    int contor=0;     //contor pentru cazul cu '-'
    struct NOD * nod_curent;

    //Conditia pentru lista goala
    if (head == NULL) {
        //Lista Goala
        return;
    }

    nod_curent = head;

    while (nod_curent != NULL) {

        produs = (nod_curent->cantitate) * (nod_curent->pret);

        if(produs>=1000){
            //Afisarea valoarea curenta si mutarea pe nodul urmator
            printf("%s\n", nod_curent->nume);
            contor = contor+1;

        }

        if(nod_curent -> cantitate >=20){
            //Afisarea valoarea curenta si mutarea pe nodul urmator
            printf("%s\n", nod_curent->nume);
            contor = contor+1;


        }

        if(contor == 0){

            printf("-");

        }

        nod_curent = nod_curent -> next;


    }


}




//Functia main care rezolva problema
int main()
{
    struct NOD * lista_persoane = NULL;

    int optiune;
    int n;      //contor pentru persoane

    int nume[256];
    int cantitate;
    int pret;


    //Citim de la tastatura optiunea
    scanf("%d", &optiune);

    //Citim de la tastatura numarul de persoane
    scanf("%d", &n);

    if(optiune == 1){
        //Punem persoanele in lista
        do{

            //Adaugam in lista valorile
            scanf("%s %d %d", nume, &cantitate, &pret);
            lista_persoane = adaugare_nod_sfarsit_lista(lista_persoane, nume, cantitate, pret);

            n=n-1;
        }while(n>=1);

    }


    afisare_lista(lista_persoane);
    afisare_lista_V1(lista_persoane);




    return 0;
}
