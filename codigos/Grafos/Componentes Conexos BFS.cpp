set<Vertice> //A
bfs(vector<vector<Vertice> > &g, vector<bool> &vis, Vertice r) {
	set<Vertice> ver; //A
	ver.insert(r); //A
	
	queue<Vertice> f;
	f.push(r);
	vis[r] = true;
	
	while(!f.empty()) {
		Vertice u = f.front();
		f.pop();
		
		for(int i = 0; i < g[u].size(); i++) {
			Vertice w = g[u][i];
			
			if(!vis[w]) {		
				ver.insert(w); //A
						
				f.push(w);
				vis[w] = true;
			}
		}
	}
	
	return ver; //A
}

// T: theta(V + E), M: theta(V) 
//(B) T: O(VlogV + E), M: theta(V)
int //B
componentesConexos(vector<vector<Vertice> > &g) {
    vector<bool> vis(g.size(), false);
    list<set<Vertice> > comp; //vértices em cada componente (A)
    int c = 0; //qtd componentes (B)
    
    for(Vertice u = 0; u < g.size(); u++)
    	if(!vis[u]) {
    		c++; //B
    		comp.push_back( //A
			bfs(g, vis, u)
			); //A
    	}
	
	return c; //B
}

