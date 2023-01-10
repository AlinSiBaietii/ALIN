#include <stdio.h>
#include <stdlib.h>


int diferenta(int v[], int n){


        int i;

        if(n==0) return 0;


        if(v[n]%5==0) return diferenta(v,n-1)+v[n];

        else return diferenta(v,n-1)-v[n];



}



 //Functia main care rezolva problema
 int main(){

    int i;
    int n;
    int rezultat;
    int v[100];

    //Setare dimensiune si citire valori vector
	printf("Introudceti nr de elemente: ");
    scanf("%d", &n);


    	//Cerem Valorile
    	for(i=0; i<n; i++){
        	scanf("%d", &v[i]);

    	}

    rezultat= diferenta(v,n);


    return 0;
 }
