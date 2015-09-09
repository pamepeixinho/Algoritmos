Retorna uma lista com os fatores primos de n.
n = P1*P2*P3*P4, sendo Pi primos e não necessariamente distintos.

list<int> fatora(int n) {
	list<int> l;
	
    while (n%2 == 0) {
    	l.push_back(2);
        n /= 2;
    }
    
    for (int i = 3; i*i <= n; i = i+2)
        while (n%i == 0) {
            l.push_back(i);
            n /= i;
        }

    if (n > 2)
    	l.push_back(n);

	return l;
}
