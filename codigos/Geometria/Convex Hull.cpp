Convex Hull � o menor pol�gono convexo que, dado um conjunto disperso de pontos P (vector<Ponto>P), 
consegue abranger no seu interior todos os pontos do conjunto P com o menor numero de arestas


bool operator <(const Ponto &p1, const Ponto &p2) {
	return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

// Fun��o que auxilia a constru��o das bordas superior e inferior.
// Verifica a "curva" da liga��o entre dois pontos consecutivos em x, o retorno
// tem o seguinte comportamento:
//    - > 0 caso ocorra uma "curva" para esquerda;
//    - < 0 caso ocorra uma "curva" para a direita;
//    - == 0 caso os pontos sejam coolineares.
int verCurva(const Ponto &O, const Ponto &A, const Ponto &B)
{
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

// Retorna a lista de pontos que representam o convex hull em ordem ant�-hor�ria.
// Obs: O �ltimo ponto da lista retornada � o mesmo que o primeiro.
vector<Ponto> convex_hull(vector<Ponto> P)
{
	int n = P.size(), k = 0;
	vector<Ponto> H(2*n);
 
	// Ordena os pontos
	// Obs: Conforme fun��o que sobrecarrega o operador "<"
	sort(P.begin(), P.end());
 
	// Constr�i a borda inferior do convex hull
	for (int i = 0; i < n; i++) {
		while (k >= 2 && verCurva(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}
 
	// Constr�i a borda inferior do convex hull
	for (int i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t && verCurva(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}
 
	H.resize(k);
	return H;
}
