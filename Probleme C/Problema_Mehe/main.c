#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definire structura arbore
struct NOD {
    char nume [256];
	int x;
	struct NOD * NOD_stanga;
	struct NOD * NOD_dreapta;
};


//Functii care ne ajuta in rezolvarea problemei

//Functie creare nod nou
struct NOD* creare_nod(char nume[], int x)
{
	struct NOD * nod_nou;


	nod_nou = (struct NOD *) malloc(sizeof(struct NOD));

	if (nod_nou == NULL)
	{
		return NULL;
	}

	//Initializare informatii
	strcpy(nod_nou->nume , nume);
	nod_nou->x = x;
	nod_nou->NOD_stanga = NULL;
	nod_nou->NOD_dreapta = NULL;

	return nod_nou;
}

//Inserare nod in arbore
struct NOD* inserare_nod(struct NOD *prim, char nume[], int x)
{
	struct NOD *nod_nou, *nod_curent, *nod_parinte;


	nod_nou = creare_nod(nume, x);

	if (prim == NULL)
	{
		//Arborele este vid
		prim = nod_nou;
		return prim;
	}


	else
	{
		//Pozitionare in arbore pe parintele nodului nou
		nod_curent = prim;

		while (nod_curent != NULL)
		{
			nod_parinte = nod_curent;

			if (x < nod_curent->x) //parcurgere spre stanga
				nod_curent = nod_curent->NOD_stanga;
			else                   //parcurgere spre dreapta
				nod_curent = nod_curent->NOD_dreapta;
		}

		//Creare legatura nod parinte cu nodul nou
		if (x < nod_parinte->x)
		{
			//Se insereaza la stanga nodului parinte
			nod_parinte->NOD_stanga = nod_nou;
		}
		else
		{
			//Se insereaza la dreapta nodului parinte
			nod_parinte->NOD_dreapta = nod_nou;
		}

		return prim;
	}
}


//Parcurgere arbore in ordine crescatoare
void afisare_crescator(struct NOD *prim)
{
	if (prim != NULL)
	{
		//Parcurgere radacina, stanga, dreapta
		afisare_crescator(prim->NOD_stanga);
		printf("%s\n", prim->nume);
		afisare_crescator(prim->NOD_dreapta);
	}
}



//Cel mai tanar membru
void membru_tanar(struct NOD *prim)
{

    struct NOD *nod_util;

    nod_util = prim;


    //Iteram la dreapta
	while (nod_util->NOD_dreapta != NULL)	{

        nod_util = nod_util->NOD_dreapta;

	}

	//Afisam numele
	printf("%s\n", nod_util->nume);


}




int main()
{

    //Definim lista
	struct NOD *persoane = NULL;
	int optiune;


	char nume[256];     //nume persoane
	int x;             //an persoane

    int n;  //numar persoane

    scanf("%d", &optiune);
    scanf("%d", &n);

    //Alegem optiunea

    //Optiunea 1

    if(optiune == 1){

        do{


	        //Scanam numele si anul
            scanf("%s", nume);
            scanf("%d", &x);

            //Le punem in lista
            persoane = inserare_nod(persoane, nume, x);

            n = n-1;


        }while(n>=1);

       afisare_crescator(persoane);

    }

    //Optiunea 2

    if(optiune == 2){


          do{


	        //Scanam numele si anul
            scanf("%s", nume);
            scanf("%d", &x);

            //Le punem in lista
            persoane = inserare_nod(persoane, nume, x);

            n = n-1;


        }while(n>=1);

       membru_tanar(persoane);


    }

    //Optiunea 3

    if(optiune == 3){


    }


	return 0;
}
