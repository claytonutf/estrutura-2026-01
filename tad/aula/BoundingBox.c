#include <stdio.h>
#include <stdlib.h>
#include "BoundingBox.h"

BoundingBox * bb_cria(int x1, int x2, int y1, int y2){
     BoundingBox *bb = (BoundingBox*) malloc(sizeof(BoundingBox));

    if (bb == NULL) {
        printf("Erro: falha na alocação de memória.\n");
        return NULL;
    }
    bb->x1 = x1;
    bb->x2 = x2;
    bb->y1 = y1;
    bb->y2 = y2;

    return bb;
}

void bb_acessa(BoundingBox* bb, 
    int *x1, int *y1, int *x2, int *y2) 
    {
    if (bb == NULL) return;

    if (x1) *x1 = bb->x1;
    if (y1) *y1 = bb->y1;
    if (x2) *x2 = bb->x2;
    if (y2) *y2 = bb->y2;
}

void bb_atribui(BoundingBox* bb, int x1, int y1, int x2, int y2) {
    if (bb == NULL) return;

    bb->x1 = x1;
    bb->y1 = y1;
    bb->x2 = x2;
    bb->y2 = y2;

    printf("%p\n",(void*)&bb->x1);
}

void bb_libera(BoundingBox* bb) {
    if (bb != NULL) {
        free(bb);
        printf("Espaço de memória liberado\n");
    }
}

int main(){
    BoundingBox * bb = bb_cria(10, 20, 7, 30);

    printf("%d\n",bb->x1);

    // acessa conteúdo de bounding box
    int x1, y1, x2, y2;
    x1=100;
    y1=150;
    x2=200;
    y2=250;
    bb_atribui(bb, x1, y1, x2, y2);
    printf("%d\n", x1);
    printf("%d\n",bb->x1);

    printf("%p\n",(void*)&x1);

    //bb_acessa(bb, &x1, &y1, &x2, &y2);
    //printf("BoundingBox: (%d, %d) até (%d, %d)\n", x1, y1, x2, y2);


    bb_libera(bb);   

    return 0;
}