Alguns Algoritmos de interseção usam funções de Basicos:
	(1) Intersecao entre dois segmentos	
	(2) Intersecao entre dois retangulos


(1)
//interseção do segmento dos pontos a e b (AB) com o segmento c e d (CD)
bool interSegSeg(Ponto a, Ponto b, Ponto c, Ponto d) {
	int i, r1, r2;
	
		if( min(a.x,b.x) > max(c.x,d.x) || max(a.x,b.x) < min(c.x,d.x) )
			return 0;
		if( min(a.y,b.y) > max(c.y,d.y) || max(a.y,b.y) < min(c.y,d.y) )
			return 0;

		//USAR FUNCAO BASICO
	r1 = prodvetsn(a, c, b) * prodvetsn(a, d, b);
	r2 = prodvetsn(c, a, d) * prodvetsn(c, b, d);
	
	return r1<=0 && r2<=0;
}

(2) 
bool interRetan(Ponto l1, Ponto r1, Ponto l2, Ponto r2){
    // If one rectangle is on left side of other
    if (l1.x > r2.x || l2.x > r1.x)
        return false;
 
    // If one rectangle is above other
    if (l1.y < r2.y || l2.y < r1.y)
        return false;
 
    return true;
}
 

