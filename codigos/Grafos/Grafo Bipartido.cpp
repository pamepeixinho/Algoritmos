vector<vector<Vertice> > g;
vector<int> cor;

int dfsCor(Vertice v, int c) { 
   cor[v] = 1-c;
   
   for (int i = 0; i < g[v].size(); i++) {
      Vertex w = g[v][i]; 
      if (cor[w] == -1) {
         if (dfsCor(w, 1-c) == 0) return 0; 
      }
      else if (cor[w] == 1-c) return 0;
   }
   return 1;
}

int bipartido() {
	cor.clear();
	cor.resize(g.size(), -1);
	
	for(Vertice u = 0; u < g.size(); u++)
		if(cor[u] == -1)
			if(dfsCor(u, 0) == 0)
				return 0;
				
	return 1;
}
