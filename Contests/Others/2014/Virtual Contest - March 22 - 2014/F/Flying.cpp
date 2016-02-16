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

struct edge{
    int start, end, weight;
    edge(int u, int v, int w){
        start = u; end = v; weight = w;
    }
    bool operator < (const edge &other) const{
        return weight < other.weight;
    }
};

const int MAXN = 100005;
vector <edge> edges;
int p[MAXN];

void initialize(int n){
    for (int i = 0; i <= n; ++i) p[i] = i;
}

int find(int u){
    if (p[u] == u) return u;
    return p[u] = find(p[u]);
}

void join(int u, int v){
    int a = find(u);
    int b = find(v);
    if (a == b) return;
    p[a] = b;
}

int kruskal(int n){
    initialize(n);
    sort(edges.begin(), edges.end());
    int total = 0;
    for (int i = 0; i < edges.size(); ++i){
        int u = edges[i].start;
        int v = edges[i].end;
        int w = edges[i].weight;
        if (find(u) != find(v)){
            total += w;
            join(u, v);
        }
    }
return total;
}


int main(){
    int cases;
    cin >> cases;
    for(int i=0;i<cases; i++){
        int n,m;
        cin >> n >> m;
        edges.clear();
        for(int j=0; j<m; j++){
            int a,b;
            cin >> a >> b;
            a--;b--;
            edges.push_back(edge(a, b, 1));
            edges.push_back(edge(b, a, 1));  
        }
        cout << kruskal(n) << endl;  
    }

	return 0;
}
