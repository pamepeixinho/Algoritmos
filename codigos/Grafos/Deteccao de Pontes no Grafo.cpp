vector<vector<Vertice> > g;
vector<int> pre, pai;
int qtdePontes, contaPre;
 
int dfs(Vertice v) {
    int minPre = pre[v] = contaPre++;
 
    for (int i = 0; i < g[v].size(); i++) {
    	Vertice w = g[v][i];
    	
        if (pre[w] == -1) {
            pai[w] = v;
            minPre = min(minPre, dfs(w));
        }
        else if (pai[v] != w)
            minPre = min(minPre, pre[w]);
    }
 
    if (minPre == pre[v])
        qtdePontes++;
 
    return minPre;
}

// T: O(V + E), M: theta(V)
int grafoPontes() {
	pre.clear();
	pre.resize(g.size(), -1);
	pai.clear();
    pai.resize(g.size(), -1);
    
	qtdePontes  = 0;
    for(Vertice u = 0; u < g.size(); u++)
    	if(pre[u] == -1) {
    		contaPre = 0;
    		dfs(u);
    	}	
    
    return qtdePontes;
}


