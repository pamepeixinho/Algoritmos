Computa a quantidade de maneiras de compor um valor monet�rio N atrav�s da jun��o de moedas considerando que os valores de moeda existentes s�o dados por S.
Podem haver mais de uma moeda com o mesmo valor; A ordem delas n�o � uma caracter�stica discriminante.

//O(mn)
int count( int S[], int m, int n ) {
 	vector<int> table(n+1, false);
    table[0] = 1;

    for(int i=0; i<m; i++)
        for(int j=S[i]; j<=n; j++)
            table[j] += table[j-S[i]];
 
    return table[n];
}
