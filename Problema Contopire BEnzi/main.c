#include "functii.h"

int main(){
    int nr_masini_banda_1;
    int nr_masini_banda_2;
    struct NOD * head_banda_1 = NULL; // punctul de intrare in coada aferenta benzii 1
    struct NOD * head_banda_2 = NULL; // punctul de intrare in coada aferenta benzii 2
    struct NOD * head_banda_3 = NULL; // in banda 3 vom retine elementele din urma contopirii benzilor 1 si 2
    char temp[8];
    
    scanf("%d", &nr_masini_banda_1);
    scanf("%d", &nr_masini_banda_2);
    
    for (int i=0; i<nr_masini_banda_1; i++){
        scanf("%s", temp);
        head_banda_1 = enqueue(head_banda_1, temp);
    }
    // afisare(head_banda_1);
    // printf("\n");
    
    for (int i=0; i<nr_masini_banda_2; i++){
        scanf("%s", temp);
        head_banda_2 = enqueue(head_banda_2, temp);
    }
    // afisare(head_banda_2);
    
    // Analizam o singura iteratie pentru adaugarea elementelor in coada 3
    // 1. Mutam un element din banda 2 in banda 3
    // 1.1. extragem prima valoare din banda 2 si o stocam in temp (peek)
    // 1.2. stergem primul element din banda 2 (dequeue)
    // 1.3. introducem temp in banda 3 (enqueue)
    // 2. Mutam un element din banda 1 in banda 3
    // 2.1. extragem prima valoare din banda 1 si o stocam in temp (peek)
    // 2.2. stergem primul element din banda 1 (dequeue)
    // 2.3. introducem temp in banda 3 (enqueue)
    
    // Repetam iteratiile pana cand ambele cozi sunt epuizate (coada 1 este epuizata si coada 2 este epuizata)
    // Conditia de oprire: ((head_banda_1 == NULL) && (head_banda_2==NULL))
    // Repetam cat timp NU este indeplinita conditia de oprire
    // !(conditie de oprire) <-> !((head_banda_1 == NULL) && (head_banda_2==NULL))
    
    while ((head_banda_1 != NULL) || (head_banda_2 != NULL)){
        if (head_banda_2 != NULL) {
            // 1.1:
            strcpy(temp, peek(head_banda_2));
            // 1.2:
            head_banda_2 = dequeue(head_banda_2);
            // 1.3:
            head_banda_3 = enqueue(head_banda_3, temp);
        }
        
        if (head_banda_1 != NULL) {
            // 2.1:
            strcpy(temp, peek(head_banda_1));
            // 2.2:
            head_banda_1 = dequeue(head_banda_1);
            // 2.3:
            head_banda_3 = enqueue(head_banda_3, temp);
        }
    }
    
    // printf("\n");
    afisare(head_banda_3);
    
    return 0;
}