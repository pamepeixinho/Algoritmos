GCD retorna o maior divisor comum entre dois inteiros(a, b).
int gcd(int a, int b){
	
	if(b == 0)
		return a;
		
	return gcd(b, a%b);
	
}