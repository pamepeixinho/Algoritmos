Retorna a soma do subarranjo que a maximiza.

//O(n)
int maxSubArraySum(int a[], int size) {
   int max_so_far = a[0], i;
   int curr_max = a[0];
 
   for (i = 1; i < size; i++) {
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
   }
   
   return max_so_far;
}
