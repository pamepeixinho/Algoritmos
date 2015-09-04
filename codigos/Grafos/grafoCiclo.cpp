vector<int> lbl;
vector<int> pai;
vector<vector<Vertice> > g;
 
bool temCicloComp(Vertice u) {
    lbl[u] = 1;
  
    for (int i = 0; i < g[u].size(); i++)
        if (g[u][i] != pai[u]) {
        	if(lbl[g[u][i]] == 1)
            	return true;	
			if(lbl[g[u][i]] == 0) {
				pai[g[u][i]] = u;
				if(temCicloComp(g[u][i]))
					return true;
			}
        }
        
    lbl[u] = 2;
    return false;
}
 
//T: O(V + E), M: theta(V + E)
bool temCiclo() {
    lbl.clear();
    lbl.resize(g.size(), 0);
    pai.clear();
    pai.resize(g.size(), -1);
    
    for(Vertice u = 0; u < g.size(); u++)
        if(lbl[u] == 0) {
        	pai[u] = u;
        	if(temCicloComp(u))
                return true;
        }
                 
    return false;
}
