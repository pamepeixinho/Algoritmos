Dado um conjuntos de pares ordenados, determina o tamanho da maior cadeia possível de se construir com esses pares que siga a restrição de que, para que dois pares (a, b) e (c, d) possam ser vizinhos, b < c.

struct pair {
  int a;
  int b;
};
 
// O(n^2)
// This function assumes that arr[] is sorted in increasing order
// according the first (or smaller) values in pairs.
int maxChainLength( struct pair arr[], int n)
{
   int i, j, max = 0;
   int *mcl = (int*) malloc ( sizeof( int ) * n );

   for ( i = 0; i < n; i++ )
      mcl[i] = 1;
 
   for ( i = 1; i < n; i++ )
      for ( j = 0; j < i; j++ )
         if ( arr[i].a > arr[j].b && mcl[i] < mcl[j] + 1)
            mcl[i] = mcl[j] + 1;
 
   for ( i = 0; i < n; i++ )
      if ( max < mcl[i] )
         max = mcl[i];

   free( mcl );
 
   return max;
}
