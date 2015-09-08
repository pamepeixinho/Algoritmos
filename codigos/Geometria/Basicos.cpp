Funções básicas usadas em distintos algoritmos tem a representacao de ponto e funções simples:
	(1)	 representacao do Ponto
	(2)  Produto Escalar
	(3)  Produto Vetorial
	(4)  Produto Vetorial (sinal)
	(5)  Teste de pertinencia de ponto em segmento
	(6)	 Distancia Euclidiana
	(7)  Pontos Colineares	
	

(1)
class Ponto{
	public:
		int x;
		int y;
		Ponto(){}	
		Ponto(int x, int y):x(x), y(y){}
		
};


(2)
long long prodEscalar(Ponto origem, Ponto a, Ponto b) {
	long long v1 = ((long long) a.x-origem.x)*(b.x-origem.x);
	long long v2 = ((long long) a.y-origem.y)*(b.y-origem.y);
	
	return v1+v2;
}

(3)
long long prodVetorial(Ponto origem, Ponto a, Ponto b) {
	long long v1 = ((long long) a.x-origem.x)*(b.y-origem.y);
	long long v2 = ((long long) a.y-origem.y)*(b.x-origem.x);
	
	return v1-v2;
}

(4)
int prodvetsn(Ponto origem, Ponto a, Ponto b) {
	long long v1 = ((long long) a.x-origem.x)*(b.y-origem.y);
	long long v2 = ((long long) a.y-origem.y)*(b.x-origem.x);

	if( v1 < v2 )  return -1;
	else if( v1 > v2 ) return +1;
	else return 0;
}

(5) 
bool interPtSeg(Ponto p, Ponto a, Ponto b) {
	return prodVetorial(p, a, b)==0 && prodEscalar(a, p, b)>=0 && prodEscalar(b, p, a)>=0;
}

(6)
double distancia(Ponto a, Ponto b){
	return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

(7)	
bool ptsColineares(Ponto a, Ponto b, Ponto c){
	
	int s = (c.y - b.y) * a.x + (b.x - c.x) * a.y + (c.x * b.y - b.x * c.y);
	
    if (s < 0 || s > 0)
        return false;
    else
        return true;
}

