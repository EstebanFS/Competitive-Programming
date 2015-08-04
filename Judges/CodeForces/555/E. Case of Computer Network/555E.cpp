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

#define MAXN 200005

int d[MAXN];
vector <int> g[MAXN];
int n;
bool side[MAXN][MAXN];

void bfs(int s, int n) {
  for(int i = 0; i <= n; ++i) d[i] = -1;
  d[s] = 0;
  queue <int> q;
  q.push(s);
  while(!q.empty()){
    int curr = q.front();
    q.pop();
    for(int i = 0; i < g[curr].size(); ++i){
      int next = g[curr][i];
      if(d[next] == 0 && (side[curr][next] == 1 || side[curr][next] == 0)) {
        side[curr][next] = 1;
        side[next][curr] = -1;
        d[next] = d[curr] + 1;
        q.push(next);
      }
    }
  }
}

int main(){
  int m, q;
  cin >> n >> m >> q;
  for(int i = 0; i <= n; ++i) g[i].clear();
  int side[n][n];
  for(int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--;
    v--,
    g[u].push_back(v);
    g[v].push_back(u);
    side[u][v] = 0;
    side[v][u] = 0;
  }
  bool can = true;
  for(int i = 0; i < q; ++i) {
    int u, v;
    cin >> u >> v;
    bfs(u, n);
    if(d[v] == -1) can = false;
  }
  if (can) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
