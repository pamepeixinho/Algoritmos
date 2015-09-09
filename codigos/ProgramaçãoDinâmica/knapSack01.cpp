// T: theta(nW), M: theta(nW), sendo W o pesoMaximo
 
int knapSack01(int pesoMaximo, int peso[], int val[], int n) {
	int i, w;
	int K[n+1][pesoMaximo + 1];
 
	for (i = 0; i <= n; i++)
	{
    	for (w = 0; w <= pesoMaximo; w++)
        {
        	if (i==0 || w==0)
        		K[i][w] = 0;
            else if (peso[i-1] <= w)
                K[i][w] = max(val[i-1] + K[i-1][w-peso[i-1]],  K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }
 
    return K[n][pesoMaximo];
}
