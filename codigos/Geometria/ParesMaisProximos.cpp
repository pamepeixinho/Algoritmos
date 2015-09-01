RESUMO PROBLEMA DOS PARES MAIS PROXIMOS
(1) codigo
(2) como usar o codigo 


(1)
bool operator <(Ponto a, Ponto b){
    return a.x < b.x;
}
 
vector<Ponto> P;

// Fun��o de compara��o para ordenar um vetor de indices(int) a partir do eixo Y do vetor de pontos P.
bool compP(int a, int b){
    if(P[a].y == P[b].y)
        return a < b;
    return P[a].y < P[b].y;
}

double parDePontosMaisProximos(int a, int b, vector<int> Y){
    // Se a quantidade de pontos a serem analisados forem de at� 3. (Caso Base)
	if(b-a <= 3){
        double md = DBL_MAX, d;
         
        for(int i = a; i < b; i++){
            for(int j = i+1; j < b; j++){
            	//faz a distancia dos 3 pontos com os 3 pontos
                d = sqrt(pow(P[i].x - P[j].x, 2.0) + pow(P[i].y - P[j].y, 2.0));
                //e ja analisa qual � melhor dist
				md = min(d, md);
            }
        }
         
        return d;
        //retorna a menor distancia
	}
	
	//conta pra dividir no eixo y
    int m = a+(b-a)/2;
    double d1, d2, md;
    vector<int> Y1(m-a), Y2(b-m);
    int i1 = 0, i2 = 0;
    for(int i = 0; i < Y.size(); i++){
        //se o indice contido em y for menor que a conta para dividir ao meio o conjunto de pontos, joga para o lado y1
		if(Y[i] < m){
            Y1[i1] = Y[i];
            i1++;
        }
        //se nao joga para o lado y2
        else{
            Y2[i2] = Y[i];
            i2++;
        }
    }
    //duas distancias- d1-Y1(lado esquerdo - de a ate m - exemplo: 0 a 2) e d2-Y2(lado direito - de m ate b - exemplo:2 a 5)
    d1 = parDePontosMaisProximos(a, m, Y1);
    d2 = parDePontosMaisProximos(m, b, Y2);
    //pega a menor distancia entre d1 e d2
	md = min(d1, d2);
     
    int tam = 0;
    vector<int> Yl(b-a);
     //ponto mais proximos no vetor yl
    for(int i = 0; i < Y.size(); i++){
        if(fabs(P[Y[i]].x - P[m].x) < md){
            Yl[tam] = Y[i];
            tam++;
        }
             
    }
    //analisa a fronteira e pontos mais proximo(menor distancia) 
    for(int i = 0; i < tam; i++){
        for(int j = i+1; j-i < 8 && j < tam; j++){
            d1 = sqrt( pow(P[Yl[i]].x - P[Yl[j]].x, 2.0) + pow(P[Yl[i]].y - P[Yl[j]].y, 2.0) );
            md = min(md, d1);
        }
    }
     
    return md;
}


(2)
    vector<int> Y;

        for(int i = 0; i < n; i++){
            cin >> P[i].x >> P[i].y;
            Y[i] = i;
        }
             
        sort(P.begin(), P.end());
        sort(Y.begin(), Y.end(), compP);
         
        d = parDePontosMaisProximos(0, n, Y);

