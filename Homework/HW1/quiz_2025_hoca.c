#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *up, *down, *left, *right;
} Node;

typedef struct {
    Node *head;
    size_t rows, cols;
} CellGrid;

CellGrid* gridcreate(int rows, int cols, int initvalue) {
    if (rows <= 0 || cols <= 0) return NULL;
    CellGrid *grid = (CellGrid*)malloc(sizeof(CellGrid));
    grid->rows = rows;
    grid->cols = cols;

    Node ***matrix = (Node***)malloc(rows * sizeof(Node**));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (Node**)malloc(cols * sizeof(Node*));
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = (Node*)malloc(sizeof(Node));
            matrix[i][j]->value = initvalue;
            matrix[i][j]->up = matrix[i][j]->down = matrix[i][j]->left = matrix[i][j]->right = NULL;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i > 0) matrix[i][j]->up = matrix[i-1][j];
            if (i < rows-1) matrix[i][j]->down = matrix[i+1][j];
            if (j > 0) matrix[i][j]->left = matrix[i][j-1];
            if (j < cols-1) matrix[i][j]->right = matrix[i][j+1];
        }
    }

    grid->head = matrix[rows/2][cols/2];

    free(matrix);
    return grid;
}

void gridupdate(CellGrid* grid, int col, int row, int newvalue) {
    if (!grid || !grid->head) return;

    Node *cur = grid->head;

    if (row < 0) for (int i = 0; i < -row && cur; i++) cur = cur->up;
    else         for (int i = 0; i < row && cur; i++) cur = cur->down;

    if (col < 0) for (int i = 0; i < -col && cur; i++) cur = cur->left;
    else         for (int i = 0; i < col && cur; i++) cur = cur->right;

    if (cur) cur->value = newvalue;
}

static Node* leftmost_of_row(CellGrid *g, int rel_row) {
    if (!g || !g->head) return NULL;
    Node *row = g->head;

    if (rel_row < 0) for (int i = 0; i < -rel_row && row; ++i) row = row->up;
    else             for (int i = 0; i < rel_row && row; ++i) row = row->down;

    if (!row) return NULL;
    while (row->left) row = row->left;
    return row;
}

void deleterow(CellGrid *g, int rowindex) {
    if (!g || !g->head || g->rows == 0) return;

    int center = (int)(g->rows / 2);
    int target_abs = center + rowindex;
    if (target_abs < 0 || target_abs >= (int)g->rows) return;

    Node *leftmost = leftmost_of_row(g, rowindex);
    if (!leftmost) return;

    int head_on_row = 0;
    int head_col_idx = -1;

    Node *leftmost_up = leftmost->up;
    Node *leftmost_down = leftmost->down;

    Node *cur = leftmost;
    int col_idx = 0;
    while (cur) {
        Node *next = cur->right;

        if (cur == g->head) { head_on_row = 1; head_col_idx = col_idx; }

        if (cur->up) cur->up->down = cur->down;
        if (cur->down) cur->down->up = cur->up;

        free(cur);
        cur = next;
        ++col_idx;
    }

    if (g->rows == 1) {
        g->head = NULL;
        g->rows = 0;
        return;
    }

    if (head_on_row) {
        Node *new_row_left = leftmost_down ? leftmost_down : leftmost_up;
        Node *new_head = new_row_left;
        for (int i = 0; i < head_col_idx && new_head; ++i) new_head = new_head->right;
        g->head = new_head ? new_head : (leftmost_down ? leftmost_down : leftmost_up);
    }

    g->rows--;
}

int sumgrid(CellGrid *g) {
    if (!g || !g->head) return 0;
    int sum = 0;

    Node *rowStart = g->head;
    while (rowStart->up) rowStart = rowStart->up;
    while (rowStart->left) rowStart = rowStart->left;

    Node *row = rowStart;
    while (row) {
        Node *cur = row;
        while (cur) {
            sum += cur->value;
            cur = cur->right;
        }
        row = row->down;
    }
    return sum;
}

int main() {
    CellGrid *g = gridcreate(5, 5, 1);
    gridupdate(g, 1, -1, 5);
    printf("Sum = %d\n", sumgrid(g));
    deleterow(g, 0);
    printf("Sum after delete = %d\n", sumgrid(g)); // Should print 24!
    return 0;
}
