Retorna o valor da soma da subsequência crescente com maior soma.

//O(n^2)
int maxSumIS( vector<int> arr, int n ) {
   int i, j, max = 0;
   vector<int> msis = arr;
   
   for ( i = 1; i < n; i++ )
      for ( j = 0; j < i; j++ )
         if ( arr[i] > arr[j] && msis[i] < msis[j] + arr[i])
            msis[i] = msis[j] + arr[i];
 
   for ( i = 0; i < n; i++ )
      if ( max < msis[i] )
         max = msis[i];

   return max;
}
