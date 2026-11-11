/*Q6) [10 pts] — Binary Trees (Recursion)
Consider the following node definition for a binary tree.
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} NODE;

Implement the function with the signature below.
int sum_leaf_nodes(NODE* root);

This function calculates and returns the sum of the data values stored in all leaf nodes of a binary tree.
A leaf node is a node that has neither a left child nor a right child.
The function must use recursion. You may assume that node values are integers.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} NODE;

// Kendi fonksiyonunu buraya yaz
int sum_leaf_nodes(NODE* root){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL){
        return root->data;
    }
    return sum_leaf_nodes(root->right) + sum_leaf_nodes(root->left);
    
    
}


// Yeni node oluşturma
NODE* create_node(int data) {
    NODE* node = malloc(sizeof(NODE));

    if (node == NULL) {
        exit(1);
    }

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// Ağacın belleğini temizleme
void free_tree(NODE* root) {
    if (root == NULL)
        return;

    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main(void) {

    // TEST 1: Example tree
    //
    //         10
    //        /  \
    //       5    15
    //      / \     \
    //     2   7     20

    NODE* root = create_node(10);
    root->left = create_node(5);
    root->right = create_node(15);
    root->left->left = create_node(2);
    root->left->right = create_node(7);
    root->right->right = create_node(20);

    printf("Test 1: %d (Expected: 29)\n",
           sum_leaf_nodes(root));

    // TEST 2: Single node tree
    NODE* single = create_node(42);

    printf("Test 2: %d (Expected: 42)\n",
           sum_leaf_nodes(single));

    // TEST 3: Empty tree
    NODE* empty = NULL;

    printf("Test 3: %d (Expected: 0)\n",
           sum_leaf_nodes(empty));

    // TEST 4: Left-skewed tree
    //
    //       10
    //      /
    //     20
    //    /
    //   30

    NODE* skewed = create_node(10);
    skewed->left = create_node(20);
    skewed->left->left = create_node(30);

    printf("Test 4: %d (Expected: 30)\n",
           sum_leaf_nodes(skewed));

    // TEST 5: Tree with negative values
    //
    //        5
    //       / \
    //     -3   8

    NODE* negative = create_node(5);
    negative->left = create_node(-3);
    negative->right = create_node(8);

    printf("Test 5: %d (Expected: 5)\n",
           sum_leaf_nodes(negative));

    free_tree(root);
    free_tree(single);
    free_tree(skewed);
    free_tree(negative);

    return 0;
}