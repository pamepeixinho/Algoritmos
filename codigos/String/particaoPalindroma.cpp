Retorna a menor quantidade de cortes necessária para particionar uma string, sendo que todas as substrings formadas são palindromos.

//O(n^2)
int minPalPartion(char *str) n{
    int n = strlen(str);
  
    int C[n][n];
    bool P[n][n];
  
    int i, j, k, L;
  
	for (i=0; i<n; i++) {
        P[i][i] = true;
        C[i][i] = 0;
    }
  

    for (L=2; L<=n; L++) {
        for (i=0; i<n-L+1; i++) {
            j = i+L-1; // Set ending index
  
            // If L is 2, then we just need to compare two characters. Else
            // need to check two corner characters and value of P[i+1][j-1]
            if (L == 2)
                P[i][j] = (str[i] == str[j]);
            else
                P[i][j] = (str[i] == str[j]) && P[i+1][j-1];
  
            // IF str[i..j] is palindrome, then C[i][j] is 0
            if (P[i][j] == true)
                C[i][j] = 0;
            else
            {
                // Make a cut at every possible localtion starting from i to j,
                // and get the minimum cost cut.
                C[i][j] = INT_MAX;
                for (k=i; k<=j-1; k++)
                    C[i][j] = min (C[i][j], C[i][k] + C[k+1][j]+1);
            }
        }
    }
  
    return C[0][n-1];
}
