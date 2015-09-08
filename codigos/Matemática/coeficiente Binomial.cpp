Retorna o coeficiente binomial(n, k) = n! / (k!(n-k)!)
Também chamado de combinatório.
			
//T: O(k), M: O(1)
int binomial(int n, int k) {
    int res = 1;
 
    if ( k > n - k )
        k = n - k;
 
    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
 
    return res;
}
