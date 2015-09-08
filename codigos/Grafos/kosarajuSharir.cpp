vector<vector<Vertice> > g;
vector<vector<Vertice> > gg; //digrafo com as arestas invertidas
vector<bool> vis;
vector<int> pos;
vector<int> comp; //componente forte de cada vertice
int qtdComps;

void dfs(vector<vector<Vertice> > &graf, Vertice v) {
    vis[v] = true;
    
    for(int i = 0; i < graf[v].size(); i++) {
        Vertice u = graf[v][i];
        if(!vis[u])
            dfs(graf, u);
    }
    
    pos.push_back(v);
    comp[v] = qtdComps;
}

//T: O(n), M: theta(n)
int kosarajuSharir() {
	vis.clear();
    vis.resize(g.size(), false);
    pos.clear();
    pos.reserve(g.size());
    comp.resize(g.size());
        
    for(Vertice u = 0; u < gg.size(); u++)
    	if(!vis[u])
			dfs(gg, u);
	
	vector<Vertice> posGG = pos;
	vis.clear();
    vis.resize(g.size(), false);
    pos.clear();
    
    qtdComps = 0;
	for(int i = 0; i < posGG.size(); i++) {
		Vertice u = posGG[i];
		if(!vis[u]) {
			dfs(g, u);
			qtdComps++;
		}
	}
	
	return qtdComps;
}

