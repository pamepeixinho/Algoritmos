Retorna o menor numero de multiplica��es escalares necess�rio para se calcular a multiplica��o de uma cadeia de matrizes.
Note que a multiplica��o de matrizes � associativa e, entre duas matrizes axb e bxc tem um custo de b multiplica��es escalares.

//O(n^3)
int MatrixChainOrder(int p[], int n) {
    int m[n][n];
    int i, j, k, L, q;

    for (i = 1; i < n; i++)
        m[i][i] = 0;
 
    for (L=2; L<n; L++)
        for (i=1; i<=n-L+1; i++) {
            j = i+L-1;
            m[i][j] = INT_MAX;
            for (k=i; k<=j-1; k++) {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
 
    return m[1][n-1];
}
