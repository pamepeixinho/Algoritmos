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


// MATRIZ DE ADJ PORRA
vector<vector<int> > g;
vector<vector<int> > rg; //digrafo residual
vector<int> pai;

bool bfs(int s, int t) {
	vector<bool> vis(g.size(), false);
    queue <int> q;
    
    q.push(s);
    vis[s] = true;
    pai[s] = -1;
 
    while (!q.empty()) {
        Vertice u = q.front();
        q.pop();
 
        for (Vertice v = 0; v < g.size(); v++)
            if (!vis[v] && rg[u][v] > 0) {
            	if(v == t)
            		return true;
            		
                q.push(v);
                pai[v] = u;
                vis[v] = true;
            }
    }
 
    return vis[t];
}
 
//T: O(EV^3)
int fordFulkerson(int s, int t) {
    rg = g;
    pai.resize(g.size());

    int max_flow = 0;

    while (bfs(s, t)) {
        int path_flow = INT_MAX;
        
        for (Vertice v = t; v != s; v = pai[v]) {
            Vertice u = pai[v];
            path_flow = min(path_flow, rg[u][v]);
        }

        for (Vertice v = t; v != s; v = pai[v]) {
            Vertice u = pai[v];
            rg[u][v] -= path_flow;
            rg[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}
