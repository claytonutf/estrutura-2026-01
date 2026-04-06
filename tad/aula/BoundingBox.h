

#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

struct boundingBox{
    int x1;
    int y1; 
    int x2;
    int y2;
};

typedef struct boundingBox BoundingBox;

// cria um novo bounding box
BoundingBox* bb_cria(int x1, int y1, int x2, int y2);


void bb_acessa(BoundingBox* bb, int* x1, int* y1, int* x2, int* y2);

void bb_atribui(BoundingBox* bb, int x1, int y1, int x2, int y2);

void bb_libera(BoundingBox* bb);

#endif