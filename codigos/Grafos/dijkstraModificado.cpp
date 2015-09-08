class HeapCS { // heap com counting sort (linear)
public:
    HeapCS(int pMin, int pMax) : pMin(pMin), pMax(pMax) {
        currentList = size = 0;
        lists = new list<Vertice>[pMax - pMin + 1];
    }
    
    ~HeapCS() {
    	delete[] lists;
    }
    
    void enqueue(Vertice v, int p) {
        lists[(p - pMin)&(pMax - pMin)].push_back(v);
        size++;     
    }
    
    Vertice dequeue() {
        while(lists[currentList].empty()) {
            currentList++;
            if(currentList == pMax - pMin + 1) currentList = 0;
        }
         
        Vertice v = lists[currentList].back();
        lists[currentList].pop_back();
        size--;
 
        return v;       
    }
    
    int pMin, pMax;
    list<Vertice> *lists;
    int currentList, size;
};

vector<int> d; //distancias

//T: O(V + E), M: theta(V + E)
void dijkstra(vector<vector<Aresta> > &g, int r, int pMin, int pMax) {
    int n = g.size();
	
	HeapCS Q(pMin, pMax);
	d.clear();
	d.resize(n, INT_MAX);
    vector<bool> cor(n, false);

    d[r] = 0;
    cor[r] = true;
    
	int u = r;
	for (int i = 0; i < g[u].size(); i++) {
        if (d[u] + g[u][i].p < d[g[u][i].v])
            d[g[u][i].v] = d[u] + g[u][i].p; //relaxamento
        if (!cor[g[u][i].v]) {
            cor[g[u][i].v] = true;
            Q.enqueue(g[u][i].v, g[u][i].p);
        }
    }
 
    while (Q.size != 0) {
        int u = Q.dequeue();
        //if(procurado == u) return;
 
        for (int i = 0; i < g[u].size(); i++) {
            if (d[u] + g[u][i].p < d[g[u][i].v])
                d[g[u][i].v] = d[u] + g[u][i].p; //relaxamento
            if (!cor[g[u][i].v]) {
                cor[g[u][i].v] = true;
                Q.enqueue(g[u][i].v, g[u][i].p);
            }
        }
    }
}
