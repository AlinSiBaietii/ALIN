#include<stdio.h>
#include<stdlib.h>

//Functii de care ne folosim


//Functii de citire
void citire(int nr_numere, int v[]){

    int i;      //Contor

    for(i=0; i<nr_numere;i++){

        scanf("%d", &v[i]);

    }

}



//Functii de afisare
int afisare(int nr_numere, int v[]){

    int i;      //Contor

    for(i=0; i<nr_numere;i++){

        printf("%d ", v[i]);

    }

}

//Functia intreg in binar
int intreg_in_binar(nr_binar){

    int rest;
    int binar=0;
    int pozitie=1;

    while(nr_binar > 0){

        //Impartim cu rest la 2 pana ajungem la 0

        rest = nr_binar%2;

        binar = binar + rest*pozitie;

        pozitie = pozitie*10;

        nr_binar = nr_binar/2;


    }

    printf("%d ", binar);


}

//Functia pentru inverare 0 si 1
int inversare_0_1(int inversare[]){


    int i;
    for(i=0; i<8;i++){

        if(inversare[i] == 0){
            inversare[i] = 1;
        }

        else
            inversare[i] = 0;


    }

    for(i=0; i<8; i++){

        printf("%d", inversare[i]);

    }





}


//Functia putere pentru binar in intreg
int pow(int x, int y){

    int i;
    int power=1;

    for(i=1; i<=y; ++i){

        power = power *x;

    }

    return power;

}


//Functia binar in intreg
int binar_in_intreg(int nr_intreg[]){

    int i;

    int intreg = 0;      //numarul intreg final
    int suma = 0;

    for(i=0; i<8; i++){

        suma=suma +  nr_intreg[i]* pow(2,i-1);

    }

    intreg = suma;

    printf("%d", intreg);



}

//Functia main care rezolva cerintele

int main(){

    int optiune;        //optiune
    int v[100];         //vector cu numere


    //Alegem optiunea
    scanf("%d", &optiune);


    //Optiunea 1

    if(optiune == 1){

        int nr_numere;      //numarul de numere
        scanf("%d", &nr_numere);


        citire(nr_numere, v);
        afisare(nr_numere, v);


    }

    //Optiunea 2

    if(optiune == 2){

        int nr_binar;
        scanf("%d", &nr_binar);

        intreg_in_binar(nr_binar);

    }

    //Optiunea 3

    if(optiune == 3){

        int u;
        int inversare[100];


        //Citim elemente
        for(u=0; u<8; u++){
            scanf("%d", &inversare[u]);

    	}

        inversare_0_1(inversare);
    }

    //Optiunea 4

    if(optiune == 4){

        int z;

        int nr_intreg[100];

        for(z=0; z<8; z++){
            scanf("%d", &nr_intreg[z]);

    	}

        binar_in_intreg(nr_intreg);
    }

    //Optiunea 5

    if(optiune == 5){


    }

    return 0;
}
