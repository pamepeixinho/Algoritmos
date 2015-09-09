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
#include <math.h>

using namespace std;

#define FOR(i,n) for(int i = 0; i < n; i++)
#define FORit(it,container) for(it = container.begin(); it != container.end(); it++)

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
