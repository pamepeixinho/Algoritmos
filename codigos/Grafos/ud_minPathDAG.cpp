#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>
#include <cfloat>
#include <climits>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

typedef int Vertice;
class Aresta {
public:
    Vertice v;
    int p;
    Aresta(Vertice v, int p) : v(v), p(p) {}
};



vector<vector<Aresta> > g
vector<Vertice> tpl;
vector<bool> vis;



vector<int> minPathDAG(Vertice r) { 
	tpl.clear();
	tpl.resize(g.size());
	vis.clear();
	vis.resize(g.size());
	
	for(Vertice u = 0; u < g.size(); u++)
		dfs(r);
	
	vector<int> d(g.size(), INT_MAX);
	
	dist[r] = 0;
    for (int i = 0; i < tpl.size(); i++) {
    	Vertice u = tpl[i];
    	
      	if(dist[u] != INT_MAX)
    		for (int j = 0; j < g[u].size(); j++) {
    			Vertice w = g[u][j].v;
		    	dist[w] = min(dist[w], dist[u] + g[u][j].p)	  	
        	}
    }
}
