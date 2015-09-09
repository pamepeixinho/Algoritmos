Quantidade existente de inteiros k tal que:
	k < n;
	k e n são coprimos => mdc(k, n) = 1, mmc(k, n) = k*n;

int phi(int n) {    
    int result = n;
 
    for (int p=2; p*p<=n; ++p) {
        if (n % p == 0) {
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }

    if (n > 1)
        result -= result / n;
    return result;
}
