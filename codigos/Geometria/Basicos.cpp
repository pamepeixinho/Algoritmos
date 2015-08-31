#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Ponto{
	public:
		int x;
		int y;
		Ponto(){}	
		Ponto(int x, int y):x(x), y(y){}
		
};

//Produto Escalar
long long prodEscalar(Ponto origem, Ponto a, Ponto b) {
	long long v1 = ((long long) a.x-origem.x)*(b.x-origem.x);
	long long v2 = ((long long) a.y-origem.y)*(b.y-origem.y);
	
	return v1+v2;
}

//Produto Vetorial
long long prodVetorial(Ponto origem, Ponto a, Ponto b) {
	long long v1 = ((long long) a.x-origem.x)*(b.y-origem.y);
	long long v2 = ((long long) a.y-origem.y)*(b.x-origem.x);
	
	return v1-v2;
}

//Produto Vetorial (sinal)
int prodvetsn(Ponto origem, Ponto a, Ponto b) {
	long long v1 = ((long long) a.x-origem.x)*(b.y-origem.y);
	long long v2 = ((long long) a.y-origem.y)*(b.x-origem.x);

	if( v1 < v2 )  return -1;
	else if( v1 > v2 ) return +1;
	else return 0;
}

//teste de pertinencia de ponto em segmento 
bool interPtSeg(Ponto p, Ponto a, Ponto b) {
	
	return prodVetorial(p, a, b)==0 && prodEscalar(a, p, b)>=0 && prodEscalar(b, p, a)>=0;
}

//Teste de Interseção de Segmentos
//interseção do segmento dos pontos a e b com o segmento c e d
bool interSegSeg(Ponto a, Ponto b, Ponto c, Ponto d) {
	int i, r1, r2;
//	for(i=0; i<2; i++)
		if( min(a.x,b.x) > max(c.x,d.x) || max(a.x,b.x) < min(c.x,d.x) )
			return 0;
		if( min(a.y,b.y) > max(c.y,d.y) || max(a.y,b.y) < min(c.y,d.y) )
			return 0;

	r1 = prodvetsn(a, c, b) * prodvetsn(a, d, b);
	r2 = prodvetsn(c, a, d) * prodvetsn(c, b, d);
	return r1<=0 && r2<=0;
}

int main (){
	return 0;
}
