
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
#define ll long long
int n, m, disjoint;
const int MAXN = 100005;
int p[MAXN];

void initialize(){
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

struct edge{
  int start, end;
  ll weight;
  edge(int u, int v, ll w){
    start = u; end = v; weight = w;
  }
    bool operator < (const edge &other) const{
    return weight < other.weight;
  }
};

vector <edge> edges;

ll kruskal(){
  initialize();
  sort(edges.begin(), edges.end());
  ll total = 0LL;
  for (int i = 0; i < edges.size(); ++i){
    int u = edges[i].start;
    int v = edges[i].end;
    ll w = edges[i].weight;
    if (find(u) != find(v)){
      disjoint--;
      total += w;
      join(u, v);
    }
  }
  return total;
}

int main() {
    while(cin >> n >> m && n) {
        map<string, int> cities;
        disjoint = n - 1;
        edges.clear();
        for(int i = 0; i < n; ++i) {
            string name;
            cin >> name;
            cities[name] = i;
        }
        for(int i = 0; i < m; ++i) {
            string su, sv;
            ll weight;
            cin >> su >> sv >> weight;
            int u = cities[su];
            int v = cities[sv];
            edges.push_back(edge(u, v, weight));
        }
        string start;
        cin >> start;
        ll ans = kruskal();
        if(!disjoint) cout << ans << endl;
        else cout << "Impossible" << endl;
    }
    return 0;
}
