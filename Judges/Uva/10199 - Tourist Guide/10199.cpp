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

#define MAXN 105
vector <int> g[MAXN];
int visited[MAXN], p[MAXN], low[MAXN], disc[MAXN], n, disc_time, root, child;
int ap[MAXN];
map<string, int> cityToN;
map<int, string> nToCity;

void articulationPoints(int u) {
  low[u] = disc[u] = disc_time++;
  for(int i = 0; i < g[u].size(); ++i) {
    int v = g[u][i];
    if(disc[v] == -1) {
      p[v] = u;
      if(u == root) child++;
      articulationPoints(v);
      if(u != root && low[v] >= disc[u]) ap[u] = true;
      if(u == root && child > 1) ap[u] = true;
      low[u] = min(low[u], low[v]);
    } else if(v != p[u]) {
      low[u] = min(low[u], disc[v]);
    }
  }
}

void clean() {
  cityToN.clear();
  nToCity.clear();
  for(int i = 0; i <= n; ++i) {
    g[i].clear();
    p[i] = -1;
    disc[i] = -1;
    ap[i] = false;
  }
  disc_time = 0;
}

int main() {
  int x = 1;
  while(cin >> n && n) {
    if(x > 1) printf("\n");
    clean();
    for(int i = 0; i < n; ++i) {
      string city;
      cin >> city;
      cityToN[city] = i;
      nToCity[i] = city;
    }
    int r;
    cin >> r;
    for(int i = 0; i < r; ++i) {
      string x, y;
      cin >> x >> y;
      g[cityToN[x]].push_back(cityToN[y]);
      g[cityToN[y]].push_back(cityToN[x]);
    }
    for(int i = 0; i < n; ++i) {
      if(disc[i] == -1) {
        root = i;
        child = 0;
        articulationPoints(i);
      }
    }
    vector<string> ans;
    for(int i = 0; i < n; ++i) if(ap[i]) ans.push_back(nToCity[i]);
    sort(ans.begin(), ans.end());
    printf("City map #%d: %d camera(s) found\n", x++, (int)ans.size());
    for(int i = 0; i < ans.size(); ++i) printf("%s\n", ans[i].c_str());
  }
}
