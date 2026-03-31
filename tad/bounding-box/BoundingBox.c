#include <stdio.h>
#include <stdlib.h>
#include "BoundingBox.h"

/*
Um código em C puro é caracterizado por usar exclusivamente recursos da linguagem C, sem depender de extensões, bibliotecas ou paradigmas de outras linguagens (principalmente C++).
*/

// cria um novo bounding box
BoundingBox* bb_cria(int x1, int y1, int x2, int y2) {

    printf("Tamanho de cada nova struct BoundingBox: %zu\n", sizeof(BoundingBox));

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
        printf("Espaço de memória liberado\n");
    }
}

// acessa os valores do bounding box
void bb_acessa(BoundingBox* bb, int *x1, int *y1, int *x2, int *y2) {
    if (bb == NULL) return;

    if (x1) *x1 = bb->x1;
    if (y1) *y1 = bb->y1;
    if (x2) *x2 = bb->x2;
    if (y2) *y2 = bb->y2;
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
}

int main() {
    BoundingBox *bb = bb_cria(0, 0, 10, 20);

    if (bb == NULL) return 1;

    int x1, y1, x2, y2;
    bb_acessa(bb, &x1, &y1, &x2, &y2);

    printf("BoundingBox: (%d, %d) até (%d, %d)\n", x1, y1, x2, y2);

    int cx, cy;
    bb_centroid(bb, &cx, &cy);
    printf("Centroide: (%d, %d)\n", cx, cy);

    bb_libera(bb);

    return 0;
}
