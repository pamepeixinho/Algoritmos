Computa o maior divisor comum entre dois inteiros a e b, usando o algoritmo de Euclides.

int mdc(int a, int b) {
	if(b == 0)
		return a;
	return mdc(b, a%b);
}
