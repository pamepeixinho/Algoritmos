// T: theta(V + E), M: theta(V) 
void bfs(vector<vector<Vertice> > &g, Vertice r) {
	vector<bool> vis(g.size(), false);
	vector<Vertice> pai(g.size(), -1); //pais, arvore de busca (A)
	vector<int> dis(g.size(), INT_MAX); //distancia ate a raiz (B)
	
	queue<Vertice> f;
	f.push(r);
	dis[r] = 0; //B
	vis[r] = true;
		
	while(!f.empty()) {
		Vertice u = f.front();
		f.pop();
		
		for(int i = 0; i < g[u].size(); i++) {
			Vertice w = g[u][i];
			
			if(!vis[w]) {
				pai[w] = u; //A
				dis[w] = dis[u] + 1; //B
				
				f.push(w);
				vis[w] = true;
			}
		}
	}
}
