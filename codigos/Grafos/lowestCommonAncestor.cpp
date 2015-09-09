Descobre o ancestral comum mais baixo de um par de vértices na árvore representada pelo vetor de paternidade F.

//as quatro variaveis abaixo ficam a ser preenchidas
int V; //qtd vertices 
int nr; //raiz quadrada da maior profundidade
int *L; //profundidade de cada vértice (considerando arestas unitárias)
int *F; //pai

int *P;

void dfs(int node) {
    int k;
 
    if (L[node] < nr)
        P[node] = 1;
    else
        if (!(L[node] % nr))
            P[node] = F[node];
        else
            P[node] = P[F[node]];
}
 
int LCA(int x, int y) {
    while (P[x] != P[y])
        if (L[x] > L[y])
            x = P[x];
        else
            y = P[y];
 
    while (x != y)
        if (L[x] > L[y])
            x = F[x];
        else
            y = F[y];
    return x;
}

void preProcess() {
    for (Vertice u = 0; u < V; u++)
        dfs(u);	
}
