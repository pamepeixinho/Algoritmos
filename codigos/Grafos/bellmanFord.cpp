vector<Vertice> o, d; //origem e destino da aresta i
vector<int> p; //peso da aresta i
vector<int> dist; 
int V, E; //numero vertices e arestas

//T: O(VE), M: O(V)
bool bellmanFord(Vertice r) {
	dist.clear();
 	dist.resize(V, INT_MAX);
    dist[r] = 0;

    for (int i = 1; i <= V-1; i++) {
        for (int j = 0; j < E; j++) {
            Vertice u = o[j], v = d[j];
            int w = p[j];
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }
 
    for (int j = 0; j < E; j++) {
        Vertice u = o[j], v = d[j];
        int w = p[j];
        if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            return 0; //contem ciclo negativo, informacoes invalidas
    }

    return 1;
}
