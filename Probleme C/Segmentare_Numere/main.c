#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definire structura arbore
struct NOD{

	int x;
	struct NOD * NOD_stanga;
	struct NOD * NOD_dreapta;

};



//Functia pentru creare nod nou
struct NOD* creare_nod(int x)
{
	struct NOD * nod_nou;

	//Alocare memorie nod
	nod_nou = (struct NOD *) malloc(sizeof(struct NOD));

	if (nod_nou == NULL)
	{
		printf("Eroare: Memoria nu a putut fi alocata! \n");
		return NULL;
	}

	//Initializare informatii (alocam valori nod)
	nod_nou->x = x;
	nod_nou->NOD_stanga = NULL;
	nod_nou->NOD_dreapta = NULL;

	return nod_nou;
}



//Inserare NOD in arbore V2
struct NOD* inserare_nod_V2(struct NOD *radacina, int x){


    if(radacina == NULL){
        return creare_nod(x);

    }

    else{

        //BST:  valorile mai mici decat parintele merg la stanga
        //      valorile mai mari decat parintele merg la dreapta

        if(x < radacina->x){
            radacina->NOD_stanga = inserare_nod_V2(radacina->NOD_stanga, x);
        }

        else{
            radacina->NOD_dreapta = inserare_nod_V2(radacina->NOD_dreapta, x);
        }

        return radacina;


    }

}



//Parcurgere arbore in ordine CRESCATOARE
void afisare_ordine_crescatoare(struct NOD *prim)
{
	if (prim != NULL)
	{
		//Parcurgere stanga, radacina, dreapta
		afisare_ordine_crescatoare(prim->NOD_stanga);
		printf("%d \n", prim->x);
		afisare_ordine_crescatoare(prim->NOD_dreapta);
	}
}


//Parcurgere arbore in ordine DESCRESCATOARE
void afisare_ordine_descrescatoare(struct NOD *prim)
{
	if (prim != NULL)
	{
		//Parcurgere stanga, radacina, dreapta
		afisare_ordine_descrescatoare(prim->NOD_dreapta);
		printf("%d \n", prim->x);
		afisare_ordine_descrescatoare(prim->NOD_stanga);
	}
}


//Functia main care rezolva problema
int main(){


    int x;  //valoare

    struct NOD * arbore_nr_pare = NULL;
    struct NOD * arbore_nr_impare = NULL;


    //Scanam pana la END OF FILE
    while(scanf("%d", &x) != EOF){

        //Verificam daca numarul este par
        if(x % 2 == 0){
            arbore_nr_pare = inserare_nod_V2(arbore_nr_pare, x);
        }

        else
            arbore_nr_impare = inserare_nod_V2(arbore_nr_impare, x);


    }


    //Afisam in ordine crescatoare nr. PARE si in ordine descrescatoare nr.  IMPARE

    afisare_ordine_crescatoare(arbore_nr_pare);
    afisare_ordine_descrescatoare(arbore_nr_impare);

    return 0;

}

