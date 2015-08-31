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
