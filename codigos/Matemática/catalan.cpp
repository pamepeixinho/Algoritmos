Retorna o catalan number Cn, sequ�ncia com a seguinte fun��o:
	C0 = 1
			  n
	Cn+1 = 	 som Ci*Cn-i
			i = 0

// T: O(n)
int catalan(int n) {
    return binomial(2*n, n)/(n+1);
}
