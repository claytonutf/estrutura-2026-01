#include <stdio.h>
#include <iostream>
#include <stdlib.h> // malloc, free
#include "BoundingBox.h"
using namespace std;

// cria um novo bounding box
BoundingBox* bb_cria(int x1, int y1, int x2, int y2) {
    BoundingBox *bb = (BoundingBox*) malloc(sizeof(BoundingBox));
    
    if (bb == NULL) {
        printf("Erro: falha na alocação de memória.\n");
        return NULL;
    }

    bb->x1 = x1;
    bb->y1 = y1;
    bb->x2 = x2;
    bb->y2 = y2;

    return bb;
}

// libera um bounding box
void bb_libera(BoundingBox* bb) {
    if (bb != NULL) {
        free(bb);
    }
}

// acessa os valores do bounding box
void bb_acessa(BoundingBox* bb, int *x1, int *y1, int *x2, int *y2) {
    if (bb == NULL) return;

    *x1 = bb->x1;
    *y1 = bb->y1;
    *x2 = bb->x2;
    *y2 = bb->y2;
}

// atribui novos valores ao bounding box
void bb_atribui(BoundingBox* bb, int x1, int y1, int x2, int y2) {
    if (bb == NULL) return;

    bb->x1 = x1;
    bb->y1 = y1;
    bb->x2 = x2;
    bb->y2 = y2;
}

// calcula o centróide (centro do retângulo)
void bb_centroid(BoundingBox* bb, int *cx, int *cy) {
    if (bb == NULL) return;

    if (cx) *cx = (bb->x1 + bb->x2) / 2;
    if (cy) *cy = (bb->y1 + bb->y2) / 2;

    /*
        cx → acessa o valor apontado pelo ponteiro
        (bb->x1 + bb->x2) / 2 → divisão inteira (já retorna int)
        if (cx) → evita erro se o ponteiro for NULL
    */
}

int main() {
    BoundingBox *bb = bb_cria(0, 0, 10, 20);

    int x1, y1, x2, y2;
    bb_acessa(bb, &x1, &y1, &x2, &y2);

    printf("%d", x2);

    // cout<<x2<<endl;

    printf("BoundingBox: (%d, %d) até (%d, %d)\n", x1, y1, x2, y2);

    int cx, cy;
    bb_centroid(bb, &cx, &cy);

    printf("Centroide: (%d, %d)\n", cx, cy);

    bb_libera(bb);

    return 0;
}