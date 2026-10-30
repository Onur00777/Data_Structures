#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cells.h"


CellGrid *gridcreate(int rows, int cols, int initvalue){ //devam
    CellGrid* grid = malloc(sizeof(CellGrid));
    grid->rows = rows;
    grid->cols = cols;
    return grid;
}

void gridupdate(CellGrid *g, int col, int row, int newvalue){
    if(g == NULL){
        return;
    }
    Node *changeNode = getnode(g, col, row);
    if (changeNode != NULL){
        changeNode->value = newvalue;
    }

}
Node *getnode(CellGrid *g, int col, int row){
    if (g== NULL || g->head== NULL){
        return NULL;
    }
    int min_row = -((int)g->rows / 2);
    int max_row = (int)g->rows - 1 - ((int)g->rows / 2);
    
    int min_col = -((int)g->cols / 2);
    int max_col = (int)g->cols - 1 - ((int)g->cols / 2);

    if (row < min_row || row > max_row || col < min_col || col > max_col){
        return NULL;
    }


    Node* search = g->head; //0,0 is the head
    if(col>0){
        for(int i = 0; i<col; i++){
            search = search->right; //sağa git
        }
    } else if(col<0){
        for(int i = 0; i>col; i--){
            search = search->left; //sola git
        }
    }

    if(row>0){
        for(int i = 0; i<row; i++){
            search = search->down; //aşağı git
        }
    } else if(col<0){
        for(int i = 0; i>row; i--){
            search = search->up; //yukarı git
        }
    }
    return search;

}
void deleterow(CellGrid *g, int rowindex); //yap
void deletecol(CellGrid *g, int colindex); //yap
int sumgrid(CellGrid *g){
    if(g == NULL){
        return 0;
    }
    //0,0 gitme
    Node* row_head = g->head;
    while(row_head->up != NULL){
        row_head = row_head->up;
    }
    while(row_head->left != NULL){
        row_head = row_head->left;
    }
    
    int sum = 0;
    while(row_head != NULL){
        Node* search = row_head;
        while(search != NULL){
            sum+= search->value;
            search = search->right; //satırda sağa git

        }
        row_head = row_head->down; //alt satır
    }
    return sum;
}
void gridfree(CellGrid *g){
    if(g == NULL){
        return;
    }
    //0,0 gitme
    Node* row_head = g->head;
    while(row_head->up != NULL){
        row_head = row_head->up;
    }
    while(row_head->left != NULL){
        row_head = row_head->left;
    }
    
    while(row_head != NULL){
        Node* alt_row = row_head->down;
        Node* search = row_head;
        while(search != NULL){
            Node* right_col = search->right;
            free(search);
            search = right_col;
        }
        row_head = alt_row; //alt satıra row_head kullanarak inemem çünkü hepsi free'lendi
    }
    free(g);

}