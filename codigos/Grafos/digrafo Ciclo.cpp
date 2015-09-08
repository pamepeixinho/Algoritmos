vector<int> lbl;
vector<vector<Vertice> > g;

bool temCicloComp(Vertice u) {
    lbl[u] = 1;
 
    for (int i = 0; i < g[u].size(); i++)
        if (lbl[g[u][i]] == 1 || (lbl[g[u][i]] == 0 && temCicloComp(g[u][i])) )
            return true;
 
    lbl[u] = 2;
    return false;
}

//T: O(V + E), M: theta(V + E)
bool temCiclo() {
	lbl.clear();
	lbl.resize(g.size(), 0);
	
	for(Vertice u = 0; u < g.size(); u++)
		if(lbl[u] == 0)
			if(temCicloComp(u))
				return true;
				
	return false;
}
