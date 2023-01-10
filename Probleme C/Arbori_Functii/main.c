#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//BST

//Definire structura arbore
struct NOD{

	int x;                      //valoarea
	struct NOD * NOD_stanga;    //NOD din stanga
	struct NOD * NOD_dreapta;   //NOD din dreapta

};


//Functii care ne vor ajuta in rezolvarea problemei


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


//Inserare NOD in arbore V1
struct NOD* inserare_nod(struct NOD *prim, int x)
{
	struct NOD *nod_nou, *nod_curent, *nod_parinte;

	nod_nou = creare_nod(x);

	if (prim == NULL)
	{
		//Arbore Vid
		prim = nod_nou;
		printf("A fost adaugat primul nod: %d. \n", prim->x);
		return prim;
	}
	else
	{
		//Pozitionare in arbore pe parintele nodului nou
		nod_curent = prim;

		while (nod_curent != NULL)
		{
			nod_parinte = nod_curent;

			if (x < nod_curent->x)  //Parcurgere spre stanga
				nod_curent = nod_curent->NOD_stanga;
			else                    //Parcurgere spre dreapta
				nod_curent = nod_curent->NOD_dreapta;
		}

		//Creare legatura nod parinte cu nodul nou
		if (x < nod_parinte->x)
		{
			//Se insereaza la stanga nodului parinte
			nod_parinte->NOD_stanga = nod_nou;
			printf("Nodul %d a fost inserat la stanga nodului %d. \n", x, nod_parinte->x);
		}
		else
		{
			//Se insereaza la dreapta nodului parinte
			nod_parinte->NOD_dreapta = nod_nou;
			printf("Nodul %d a fost inserat la dreapta nodului %d.\n",
				x, nod_parinte->x);
		}

		return prim;
	}
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

//Parcurgere arbore in preordine
void afisare_preordine(struct NOD *prim)
{
	if (prim != NULL)
	{
		//Parcurgere radacina, stanga, dreapta
		printf("%d \n", prim->x);
		afisare_preordine(prim->NOD_stanga);
		afisare_preordine(prim->NOD_dreapta);
	}
}

//Parcurgere arbore in inordine
void afisare_inordine(struct NOD *prim)
{
	if (prim != NULL)
	{
		//Parcurgere stanga, radacina, dreapta
		afisare_inordine(prim->NOD_stanga);
		printf("%d \n", prim->x);
		afisare_inordine(prim->NOD_dreapta);
	}
}

//Parcurgere arbore in postordine
void afisare_postordine(struct NOD *prim)
{
	if (prim != NULL)
	{
		//Parcurgere stanga, dreapta, radacina
		afisare_postordine(prim->NOD_stanga);
		afisare_postordine(prim->NOD_dreapta);
		printf("%d \n", prim->x);
	}
}

//Stergerea unui arbore sau subarbore
struct NOD* stergere_arbore(struct NOD *tmp)
{
	if (tmp != NULL)
	{
		stergere_arbore(tmp->NOD_stanga);
		stergere_arbore(tmp->NOD_dreapta);
		free(tmp);
	}

	return NULL;
}

//Cautarea unui nod dorit
struct NOD* cauta_nod(struct NOD *tmp, int x)
{
	if (tmp != NULL)
	{
		if (x == tmp->x)
		{
			printf("Nodul a fost gasit. \n");
			return tmp;
		}
		else if (x < tmp->x)
			return cauta_nod(tmp->NOD_stanga, x);
		else
			return cauta_nod(tmp->NOD_dreapta, x);
	}
	else
	{
		printf("Nodul dorit nu exista in arbore.\n");
		return NULL;
	}
}


//Afisare Adancime
int adancime(struct NOD * radacina){


    int adancime_stanga;
    int adancime_dreapta;


    if( radacina == NULL){

        return 0;

    }

    else{

        adancime_stanga = adancime(radacina->NOD_stanga);
        adancime_dreapta = adancime(radacina->NOD_dreapta);

        if(adancime_stanga < adancime_dreapta){
            return adancime_dreapta + 1;

        }

        else
            return adancime_stanga + 1;

    }

}


//Afisarea unui NIVEL la alegere (vedem elementele de pe un nivel)
void afisare_nivel_n(struct NOD * radacina, int nivel){

    if((radacina == NULL) || (nivel <= 0)){
        return ;
    }

    if (nivel == 1){

        printf("%d ", radacina->x);
    }

    else{

        afisare_nivel_n(radacina->NOD_stanga, nivel-1);
        afisare_nivel_n(radacina->NOD_dreapta, nivel-1);

    }


}


//Afisare BREADTH FIRST TRAVERSAL == AFISAM FIECARE NIVEL
void breadth_first_traversal(struct NOD *radacina){

    int i;      //Contor


    //Calculam adancimea
    int adancime_max = adancime(radacina);

    for(int i=1; i<=adancime_max; i++){

        afisare_nivel_n(radacina,i);
        printf("\n");

    }



}



//Functia main care ne rezolva problema

int main()
{

    //Declaram arborele
	struct NOD *prim = NULL;
	struct NOD *nod_gasit;

	//Declaram Variabilele
	int operatie;
	int x;

	printf("MENIU: \n");
	printf("[1] Inserare nod in arbore \n");
	printf("[2] Afisare arbore preordine \n");
	printf("[3] Afisare arbore inordine \n");
	printf("[4] Afisare arbore postordine \n");
	printf("[5] Stergere arbore \n");
	printf("[6] Cautare nod in arbore \n");
	printf("[7] Afisare adancime \n");
	printf("[8] Afisare elemente de pe un nivel \n");
	printf("[9] Breadth First Traversal");
	printf("[0] Iesire din program \n");

	do {
		printf("\nIntroduceti operatie: ");
		scanf("%d", &operatie);

		printf("\n");
		switch (operatie)
		{
			case 1:
				printf("#Inserare nod in arbore# \n");
				printf("Introduceti valoarea nodului care va fi inserat: ");
				scanf("%d", &x);
				prim = inserare_nod(prim, x);
				break;

			case 2:
				printf("#Afisare arbore preordine# \n");
				if (prim == NULL)
					printf("Atentie: Arborele este gol.");
				else
					afisare_preordine(prim);
				break;

			case 3:
				printf("#Afisare arbore inordine# \n");
				if (prim == NULL)
					printf("Atentie: Arborele este gol.");
				else
					afisare_inordine(prim);
				break;

			case 4:
				printf("Afisare arbore postordine: \n");
				if (prim == NULL)
					printf("Atentie: Arborele este gol.");
				else
					afisare_postordine(prim);
				break;

			case 5:
				printf("#Stergere arbore# \n");
				if (prim == NULL)
					printf("Atentie: Arborele este gol.");
				else
				{
					printf("Introduceti valoarea nodul al carui arbore va fi sters: ");
					scanf("%d", &x);
					nod_gasit = cauta_nod(prim, x);
					if (nod_gasit != NULL)
					{
						nod_gasit->NOD_stanga =
							stergere_arbore(nod_gasit->NOD_stanga);
						nod_gasit->NOD_dreapta =
							stergere_arbore(nod_gasit->NOD_dreapta);
						printf("Arborele a fost sters. \n");
					}
				}
				break;

			case 6:
				printf("#Cautare nod in arbore# \n");
				if (prim == NULL)
					printf("Atentie: Arborele este gol.");
				else
				{
					printf("Introduceti valoarea nodului: ");
					scanf("%d", &x);
					cauta_nod(prim, x);
				}
				break;


            case 7:
				printf("#Aflare adancime maxima# \n");
				if (prim == NULL)
					printf("Atentie: Arborele este gol.");
				else
				{
					printf("Adancimea maxima este: %d ", adancime(prim));

				}
				break;


            case 8:
				printf("#Afisare elemente de pe un nivel# \n");
				if (prim == NULL)
					printf("Atentie: Arborele este gol.");

				else
				{
				    int nivel;

				    printf("Introduceti nivelul: ");
				    scanf("%d", &nivel);


					printf("Afisare elemente nivel: %d\n", nivel);
					afisare_nivel_n(prim, nivel);


				}
				break;


            case 9:
				printf("#Breadth First Traversal# \n");
				if (prim == NULL)
					printf("Atentie: Arborele este gol.");
				else
				{
					printf("Afisare arbore pe latime: \n");
					breadth_first_traversal(prim);

				}
				break;


			case 0:
				printf("Iesire din program \n");
				stergere_arbore(prim);
				return 0;
				break;

			default:
				printf("Operatie invalida \n");
		}
	} while (1);


	return 0;
}
