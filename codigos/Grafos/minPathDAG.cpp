vector<vector<Aresta> > g;
vector<Vertice> tpl;
vector<bool> vis;

void dfs(Vertice u) {
	vis[u] = true;
	
	for(int i = 0; i < g[u].size(); i++)
		if(!vis[g[u][i].v])
			dfs(g[u][i].v);

	tpl.push_back(u);
}

//T: O(V + E), M: theta(V)
vector<int> minPathDAG(Vertice r) { 
	tpl.clear();
	tpl.reserve(g.size());
	vis.clear();
	vis.resize(g.size(), false);
	
	dfs(r);
	vector<int> dist(g.size(), INT_MAX);
	
	dist[r] = 0;
    for (int i = tpl.size() - 1; i >= 0; i--) {
    	Vertice u = tpl[i];
    	
      	if(dist[u] != INT_MAX)
    		for (int j = 0; j < g[u].size(); j++) {
    			Vertice w = g[u][j].v;
		    	dist[w] = min(dist[w], dist[u] + g[u][j].p);	
        	}
    }
}
