// T: theta(nW), M: theta(W), sendo W o pesoMaximo

int knapSackIlimitado(int pesoMaximo, int peso[], int val[], int n) {
	int i, w;
	int K[pesoMaximo + 1];
  
	K[0] = 0;
	for (w = 1; w <= pesoMaximo; w++) {
		K[w] = 0;
		
		for(int i = 0; i < n; i++)
           if(peso[i] <= w)
               K[w] = max(K[w], K[w - peso[i]] + val[i]);
	}
	
	return K[pesoMaximo];
}
