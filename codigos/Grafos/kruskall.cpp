class Aresta {
public:
    Vertice a, b;
    unsigned long long int d;
    static bool comp(const Aresta &a, const Aresta &b) {
        return a.d < b.d;
    }
};

//O(E)
unsigned long long int kruskal(int M, Aresta *a, int N)
{
    int *t = new int[M];
    for(int i=0; i<M; i++)
        t[i] = i;
     
    sort(a, a+N, Aresta::comp);
     
    Aresta nova;
    unsigned long long int pesoTotal = 0;
    for(int i=0, j=0; i<M-1; i++) {
        do
            nova = a[j++];
        while(t[nova.a] == t[nova.b]);
             
        pesoTotal += nova.d;
         
        int maior = max(t[nova.a], t[nova.b]), menor = t[nova.a] + t[nova.b] - maior;
        for(int i=0; i<M; i++)
            if(t[i] == maior)
                t[i] = menor;
    }
     
    delete[] t;
    return pesoTotal;
}
