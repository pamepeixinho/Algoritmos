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
class ArestaOP {
public:
    Vertice o, p;
    int w;
    ArestaOP(Vertice o, Vertice p, int w) : o(o), p(p), w(w) {}
};

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


