O algoritmo KMP faz a busca de todas as ocorrências de um padrão em uma string.
É o algoritmo mais eficiente para matching O(n).

vector<int> f; //Vetor de falha
void prefixFunction(string P) {
	f.resize(P.size());
	f[0] = 0;
	int m = P.size();
	int j = 0;
	int i = 1;
	while (i < m) {
		if (P[j] == P[i]) {
			f[i] = j + 1;
			i++;
			j++;
		}
		else if (j > 0)
			j = f[j - 1];
		else{
			f[i] = 0;
			i++;
		}
	}
}
//BUSCA SUBSTRING - O(n)
int KMPmatch(string P, string T)/*(Padrão, texto)*/{
	int n = T.size();
	int m = P.size();
	prefixFunction(P);
	int i = 0;
	int j = 0;
	while (i < n) {
		if (P[j] == T[i]){
			if (j == m - 1)
				cout<<"found at: "<<i-m+1<<endl;
//				return i - m + 1;
			i++;
			j++;
		}
		else if (j > 0){
			j = f[j - 1];
		}
		else{
			i++;
		}
	}
	return -1;
}
