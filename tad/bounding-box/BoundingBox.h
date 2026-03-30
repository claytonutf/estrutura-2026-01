
// Estas instruções querem dizer: “Inclua este arquivo apenas uma vez.”
#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H


// arquivo BoundingBox.h

struct boundingBox{
    int x1;
    int y1; 
    int x2;
    int y2;
};

typedef struct boundingBox BoundingBox;

// cria um novo bounding box
BoundingBox* bb_cria(int x1, int y1, int x2, int y2);

// libera um bounding box
void bb_libera(BoundingBox* bb);

// acessa os valores x1, x2, y1, y2 de um bounding box
void bb_acessa(BoundingBox* bb, int* x1, int* y1, int* x2, int* y2);

// atribui os valores "x" e "y" a um ponto
void bb_atribui(BoundingBox* bb, int x1, int y1, int x2, int y2);

//Calcula a distância entre dois pontos
void bb_centroid(BoundingBox* bb, int* cx, int* cy);


#endif