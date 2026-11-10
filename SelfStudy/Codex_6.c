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
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} NODE;

int sum_leaf_nodes(NODE* root){
    int count= 0;
    if(root->left == NULL && root->right == NULL){
        count = root->data;
    }
    if(root->left == NULL) return count + sum_leaf_nodes(root->right);
    else return count + sum_leaf_nodes(root->left);
}