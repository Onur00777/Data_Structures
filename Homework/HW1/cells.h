#ifndef CELLS_H
#define CELLS_H

typedef struct Node {
    int value;
    struct Node *up, *down, *left, *right;
} Node;

typedef struct {
    Node *head; //Points to the center
    size_t rows, cols;
} CellGrid;

CellGrid *gridcreate(int rows, int cols, int initvalue); //create dimensions
void gridupdate(CellGrid *g, int col, int row, int newvalue);
Node *getnode(CellGrid *g, int col, int row);
void deleterow(CellGrid *g, int rowindex);
void deletecol(CellGrid *g, int colindex);
int sumgrid(CellGrid *g);
void gridfree(CellGrid *g);

#endif