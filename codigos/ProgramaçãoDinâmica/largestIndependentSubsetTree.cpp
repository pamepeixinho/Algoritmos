Computa o tamanho do maior subconjunto independente de uma dada árvore binária.
Um conjunto de vértices é dito independente se, para nenhum par de vértices pertencentes ao conjunto, há uma aresta conectando-os.

struct node
{
    int data;
    struct node *left, *right;
};
 
// The function returns size of the largest independent set in a given 
// binary tree
int LISS(struct node *root)
{
    if (root == NULL)
       return 0;
 
    // Caculate size excluding the current node
    int size_excl = LISS(root->left) + LISS(root->right);
 
    // Calculate size including the current node
    int size_incl = 1;
    if (root->left)
       size_incl += LISS(root->left->left) + LISS(root->left->right);
    if (root->right)
       size_incl += LISS(root->right->left) + LISS(root->right->right);
 
    // Return the maximum of two sizes
    return max(size_incl, size_excl);
}
