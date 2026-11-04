#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cells.h"


CellGrid *gridcreate(int rows, int cols, int initvalue){
    if (rows <= 0 || cols <= 0){
        return NULL;
    }

    CellGrid* grid = malloc(sizeof(CellGrid));
    if (grid == NULL){
        return NULL;
    }
    grid->rows = (size_t)rows;
    grid->cols = (size_t)cols;
    grid->head = NULL;

    /* Geçici tablo: komşuyu bulmak için. Düğümler değil, sadece adresler.
       Fonksiyon dönmeden free edilir; ızgara bu tabloyu tutmaz. */
    size_t count = (size_t)rows * (size_t)cols;
    Node **cells = malloc(count * sizeof(Node *));
    if (cells == NULL){
        free(grid);
        return NULL;
    }

    for (int r = 0; r < rows; r++){
        for (int c = 0; c < cols; c++){
            Node *node = malloc(sizeof(Node));
            if (node == NULL){
                size_t made = (size_t)r * (size_t)cols + (size_t)c;
                for (size_t i = 0; i < made; i++){
                    free(cells[i]);
                }
                free(cells);
                free(grid);
                return NULL;
            }
            node->value = initvalue;
            node->up = NULL;
            node->down = NULL;
            node->left = NULL;
            node->right = NULL;
            cells[(size_t)r * (size_t)cols + (size_t)c] = node;
        }
    }

    for (int r = 0; r < rows; r++){
        for (int c = 0; c < cols; c++){
            Node *node = cells[(size_t)r * (size_t)cols + (size_t)c];
            if (c + 1 < cols){
                Node *right = cells[(size_t)r * (size_t)cols + (size_t)c + 1];
                node->right = right;
                right->left = node;
            }
            if (r + 1 < rows){
                Node *down = cells[((size_t)r + 1) * (size_t)cols + (size_t)c];
                node->down = down;
                down->up = node;
            }
        }
    }

    /* Merkez: fiziksel satır rows/2, sütun cols/2. Çift boyutta alt ve sağ orta. */
    grid->head = cells[(size_t)(rows / 2) * (size_t)cols + (size_t)(cols / 2)];
    free(cells);
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
    } else if(row<0){ 
        for(int i = 0; i>row; i--){
            search = search->up; //yukarı git
        }
    }
    return search;

}
/* Kalan ızgarada head'i yeniden seçer: fiziksel satır rows/2, sütun cols/2. */
static void sethead(CellGrid *g, Node *node){
    while(node->up != NULL){
        node = node->up;
    }
    while(node->left != NULL){
        node = node->left;
    }

    for(size_t r = 0; r < g->rows / 2; r++){
        node = node->down;
    }
    for(size_t c = 0; c < g->cols / 2; c++){
        node = node->right;
    }
    g->head = node;
}

void deleterow(CellGrid *g, int rowindex){
    if(g == NULL || g->head == NULL || g->rows <= 1){
        return;
    }

    int min_row = -((int)g->rows / 2);
    int max_row = (int)g->rows - 1 - ((int)g->rows / 2);
    if(rowindex < min_row || rowindex > max_row){
        return;
    }

    Node *row = getnode(g, 0, rowindex);
    if(row == NULL){
        return;
    }
    while(row->left != NULL){
        row = row->left;
    }

    /* Son satır silinmediği için üst ya da alt komşu duruyordur. */
    Node *anchor = (row->up != NULL) ? row->up : row->down;
    if(anchor == NULL){
        return;
    }

    while(row != NULL){
        Node *next = row->right;
        if(row->up != NULL){
            row->up->down = row->down;
        }
        if(row->down != NULL){
            row->down->up = row->up;
        }
        free(row);
        row = next;
    }

    g->rows -= 1;
    sethead(g, anchor);
}

void deletecol(CellGrid *g, int colindex){
    if(g == NULL || g->head == NULL || g->cols <= 1){
        return;
    }

    int min_col = -((int)g->cols / 2);
    int max_col = (int)g->cols - 1 - ((int)g->cols / 2);
    if(colindex < min_col || colindex > max_col){
        return;
    }

    Node *col = getnode(g, colindex, 0);
    if(col == NULL){
        return;
    }
    while(col->up != NULL){
        col = col->up;
    }

    Node *anchor = (col->left != NULL) ? col->left : col->right;
    if(anchor == NULL){
        return;
    }

    while(col != NULL){
        Node *next = col->down;
        if(col->left != NULL){
            col->left->right = col->right;
        }
        if(col->right != NULL){
            col->right->left = col->left;
        }
        free(col);
        col = next;
    }

    g->cols -= 1;
    sethead(g, anchor);
}
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