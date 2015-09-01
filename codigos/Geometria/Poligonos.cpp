A representação de Poligonos é a apresentada no (1), algoritmos relacionados com poligonos:
	(1) Representacao Poligono
	(2) Area do Poligono	//TESTAR*****************
	(3) Teste de pertinencia do Ponto no Poligono (isInside()) 	//TESTAR*****************


(1)
vector<Ponto> Poligono;

(2)	//TESTAR*****************
double areaPoligono(vector<Ponto> Poligono){
    
	double total = 0;
    
	for (int i = 0; i < Poligono.size(); i++){
        int j = (i + 1) % Poligono.size();
        total += (Poligono[i].x * Poligono[j].y) - (Poligono[j].x * Poligono[i].y);
    }
    return total / 2;
}

(3)	//TESTAR*****************
#define INF 10000
// 		Basicos (5) - interPtSeg (q,p,r)
//		Intersecao(1) -  interSegSeg(p1,q1,p2,q2)
 

// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Ponto p, Ponto q, Ponto r){
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}

// Returns true if the Ponto p lies inside the Poligono
bool isInside(vector<Ponto> Poligono, Ponto p){
	
    if (Poligono.size() < 3)  return false;

    Ponto extreme = {INF, p.y};
 
    int count = 0, i = 0;
    
	do{
        int next = (i+1)%Poligono.size();
 
        if (interSegSeg(Poligono[i], Poligono[next], p, extreme)) {
            if (orientation(Poligono[i], p, Poligono[next]) == 0)
               return interPtSeg(p, Poligono[i], Poligono[next]);
 
            count++;
        }
        
        i = next;
    } while (i != 0);
 
    return count&1;  // Same as (count%2 == 1)
}
