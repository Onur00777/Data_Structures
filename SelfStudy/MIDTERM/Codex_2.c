typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} NODE;
// This function counts the number of nodes in a binary tree that have exactly one child (either a left child or a right child, but not both).
int count_single_child_nodes(NODE* root){
    if(root == NULL)return;
    int left = 0;
    int right = 0;
    int one_or_zero = 0;
    NODE* new = root; 
    if(new->left != NULL) left = 1;
    if(new->right != NULL) right = 1;
    if((left == 1 && right == 0)||(left == 0 && right == 1)) one_or_zero = 1;

    return one_or_zero + count_single_child_nodes(root->left) + count_single_child_nodes(root->right);
}