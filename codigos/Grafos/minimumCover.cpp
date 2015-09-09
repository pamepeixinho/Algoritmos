Encontra a cobertura mínima de um grafo, que é um conjunto que segue a seguinte regra: Para toda aresta (u,w) do grafo, ou u ou w estão inclusos na cobertura.
Se difere de uma bipartição pois OR é diferente de XOR.

struct node {
    int data;
    int vc;
    struct node *left, *right;
};
 

int vCover(struct node *root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 0;
 
    if (root->vc != 0)
        return root->vc;
 
    // Calculate size of vertex cover when root is part of it
    int size_incl = 1 + vCover(root->left) + vCover(root->right);
 
    // Calculate size of vertex cover when root is not part of it
    int size_excl = 0;
    if (root->left)
      size_excl += 1 + vCover(root->left->left) + vCover(root->left->right);
    if (root->right)
      size_excl += 1 + vCover(root->right->left) + vCover(root->right->right);
 
    // Minimum of two values is vertex cover, store it before returning
    root->vc =  min(size_incl, size_excl);
 
    return root->vc;
}

