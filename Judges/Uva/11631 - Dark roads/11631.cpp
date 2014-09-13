//Esteban Foronda Sierra
using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r;}

#define D(x) cout << #x " is " << x << endl
#define NULO -1

typedef pair <int, int> edge;
typedef pair <int, int> dist_node;
const long long INF = 1 << 31;
const int MAXN = 200005;
int n, m, a, b;
vector <edge> g[MAXN];
priority_queue <dist_node, vector <dist_node>,
                greater<dist_node> > pend;
long long dist[MAXN], aPrim, tot, w;
bool perm[MAXN];

void
limpiar() {
    for(int l = 0; l < n; l++) {
        g[l].clear();
        perm[l] = false;
        dist[l] = INF;
    }
    pend = priority_queue <dist_node, vector <dist_node>,
                           greater<dist_node> >();
}

void
leerPrim() {
    limpiar();
    for(int cont = 0; cont < m; cont++) {
        cin >> a >> b >> w;
        g[a].push_back(edge(b, w));
        tot += w;
        if(a != b) g[b].push_back(edge(a, w));
   }
}

void
calcularPrim(int nodo) {
    pend.push(dist_node(0, nodo));
    while(!pend.empty()){
        int dist = pend.top().first;
        int cur = pend.top().second;
        pend.pop();
        if(perm[cur]) continue;
        aPrim += dist;
        perm[cur] = true;
        for(int i = 0; i < g[cur].size(); i++) {
            int tNodo = g[cur][i].first;
            int tDis = g[cur][i].second;
            if(!perm[tNodo]) pend.push(dist_node(tDis, tNodo));   
        }
    }
}

int
main() {
    while(cin >> n >> m && n != 0 && m != 0) {
        tot = 0;
        leerPrim();
        aPrim = 0;
        calcularPrim(0);
        cout << (tot - aPrim) << endl;
    }   
    return 0;
}
