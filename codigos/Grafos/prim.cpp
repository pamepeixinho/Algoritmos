//T: O(ElogV), M: (E + V)
int prim(vector<vector<Aresta> > &g) {
	vector<bool> pego(g.size(), false);
	multiset<ArestaOP> cand;

	pego[0] = true;	
	for(int i = 0; i < g[0].size(); i++)
		cand.insert(ArestaOP(0, g[0][i]));
	
	int peso = 0;
	for (int i = 0; i < g.size() - 1; i++) {
		ArestaOP a;
		do {
			if(cand.empty()) return -1; // desconexo
						
			multiset<ArestaOP>::iterator it = cand.begin();
			a = *it;
			cand.erase(it);
		} while (pego[a.p]);

		peso += a.w;
		
		Vertice u = a.p;
		pego[u] = true;
		for(int i = 0; i < g[u].size(); i++)
			cand.insert(ArestaOP(u, g[u][i]));
	}

	return peso;
}
