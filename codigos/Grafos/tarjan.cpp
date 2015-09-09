vector<vector<Vertice> > g;
vector<int> pre;
vector<int> low;
vector<int> sc; //componente forte de cada vertice
stack<Vertice> pil;
int kk;
int N;
int scnum;

void dfs(Vertice v) { 
   pre[v] = kk++; 
   low[v] = pre[v]; 
   pil.push(v);
   
   for (int i = 0; i < g[v].size(); i++) {
      Vertice w = g[v][i];
      if (pre[w] == -1) 
         dfs(w);
      if (low[w] < low[v]) 
         low[v] = low[w];
   }
   
   if (low[v] < pre[v])
      return; 
      
   do { 
      Vertice u = pil.top();
	  pil.pop(); 
      sc[u] = scnum; 
      low[u] = g.size(); 
   } while (pil.top() != v); 
   scnum++;
}

//T: O(n)
int tarjan() {
    pre.clear();
	pre.resize(g.size(), -1);
	low.clear();
	low.resize(g.size());
	sc.clear();
	sc.resize(g.size());
	
    scnum = 0; N = 0; kk = 0;
	for(Vertice u = 0; u < g.size(); u++)
		if(pre[u] == -1)
			dfs(u);
}


