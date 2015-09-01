vector<int> d; //distancias
 
bool comp(const int A, const int B) {
    return d[A] > d[B];
}

//T: O(ElogV), M: theta(V + E)
void dijkstra(vector<vector<Aresta> > &g, int r) {
    int n = g.size();
	
	vector<Vertice> Q;
	d.clear();
	d.resize(n, INT_MAX);
    vector<bool> cor(n, false);

    Q.push_back(r);
    d[r] = 0;
    cor[r] = true;
 
    while (!Q.empty()) {
        int u = Q[0];
        //if(procurado == u) return;
        pop_heap(Q.begin(), Q.end(), comp); 
		Q.pop_back();
 
        for (int i = 0; i < g[u].size(); i++) {
            if (d[u] + g[u][i].p < d[g[u][i].v])
                d[g[u][i].v] = d[u] + g[u][i].p; //relaxamento
            if (!cor[g[u][i].v]) {
                cor[g[u][i].v] = true;
                Q.push_back(g[u][i].v);
            }
        }
 
        make_heap(Q.begin(), Q.end(), comp);
    }
}
