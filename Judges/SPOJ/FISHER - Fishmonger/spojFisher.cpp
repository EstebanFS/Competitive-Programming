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
#define MAXN 2500
#define ll long long
int n, tl, t;
int dist[MAXN][MAXN];
int tim[MAXN][MAXN];
ll d;
vector<int> g[MAXN];
ll max_value = 100000000;

void dfs(int u, ll currD, int currT, vector<bool> visited) {
  if(currT > tl) return;
  for(int i = 0; i < n; ++i) {
    if(i == n - 1) {
      currD += dist[u][i];
      currT += tim[u][i];
      if(currD < d && currT <= tl) {
        //D(currD); D(currT);
        d = currD;
        t = currT;
      }
      continue;
    }
    //D(u); D(i); D(currD + dist[u][i]); D(currT + tim[u][i]);
    visited[u] = true;
    if(!visited[i]) dfs(i, currD + dist[u][i], currT + tim[u][i], visited);
  }
}

void clean() {

}



int main() {
  while(cin >> n >> tl && (n != 0 && tl != 0)) {
    for(int i = 0; i <= n; ++i) g[i].clear();
    t = 1005;
    d = max_value;
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) cin >> tim[i][j];
    }
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) cin >> dist[i][j];
    }
    vector<bool> visited(n);
    for(int i = 0; i < n; ++i) visited[i] = false;
    visited[0] = true;
    dfs(0, 0, 0, visited);
    printf("%lld %d\n", d, t);
  }
  return 0;
}
