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
#define MAXN 1000005
#define WHITE 0
#define GRAY 1
#define BLACK 2

vector<int> g[MAXN];
vector<int> topo_sort;
int visited[MAXN];
bool cicle;
int n, m;

void dfs(int u) {
  visited[u] = GRAY;
  for(int i = 0; i < g[u].size(); ++i) {
    int v = g[u][i];
    if(visited[v] == WHITE) dfs(v);
    else if(visited[v] == GRAY) {
      cicle = true;
      return;
    }
  }
  visited[u] = BLACK;
  topo_sort.push_back(u);
}

void topological() {
  topo_sort.clear();
  for(int i = 0; i < n; ++i) {
    if(visited[i] == WHITE) {
      if(!cicle) dfs(i);
      else return;
    }
  }
  reverse(topo_sort.begin(), topo_sort.end());
}


void clean() {
	cicle = false;
  for(int i = 0; i < n; ++i) {
    g[i].clear();
    visited[i] = WHITE;
  }
}

int main() {
  while(cin >> n >> m && (n != 0 && m != 0)) {
    clean();
    for(int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y;
      x--; y--;
      g[x].push_back(y);
    }
    topological();
    if(cicle) cout << "IMPOSSIBLE" << endl;
    else for(int i = 0; i < n; ++i) cout << topo_sort[i] + 1 << endl;
  }
  return 0;
}

