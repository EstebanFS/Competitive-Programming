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

using namespace std;

typedef long long ll;
#define D(x) cout << #x << " " << x << endl
#define MAXN 25
#define MAXM 1005
char board[MAXN][MAXM];
int n, m, x = 1;
int connections[MAXN * MAXM];
vector <int> g[MAXN * MAXM];
int numerals[MAXN * MAXM];

int main() {
  while(cin >> n >> m) {
    if(n == 0 && m == 0) break;
    getchar();
    int node = 0;
    for(int i = 0; i <= n * m; ++i) {
      g[i].clear();
      numerals[i] = false;
    }
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < m; ++j) {
        char curr = getchar();
        board[i][j] = curr;
        node++;
        if(board[i][j] == '#') {
          numerals[node - 1] = true;
          continue;
        }
        if((j - 1) >= 0 && board[i][j - 1] == '.') {
          g[node - 1].push_back(node - 2);
          g[node - 2].push_back(node - 1);
          //printf("Connect 1 %d with %d\n", node - 1, node - 2);
        }
        if((i - 1) >= 0 && board[i - 1][j] == '.') {
          g[node - 1].push_back(node - m - 1);
          g[node - m - 1].push_back(node - 1);
          //printf("Connect 2 %d with %d\n", node - 1, node - m - 1);
        }
      }
      getchar();
    }
    int half = 0;
    queue<int> q;
    for(int i = 0; i < node; ++i) {
      if(g[i].size() == 1) q.push(i);
      connections[i] = g[i].size();
      //D(i);D(numerals[i]);D(connections[i]);
      if(!numerals[i] && connections[i] == 0) half++;
    }
    while(!q.empty()) {
      int u = q.front();
      q.pop();
      if(connections[u] == 0) continue;
      for(int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        connections[v] = 0;
        for(int j = 0; j < g[v].size(); ++j) {
          int next = g[v][j];
          if(connections[next] == 0 || next == u) continue;
          if(connections[next] > 0) connections[next]--;
          if(connections[next] == 0) half++;
          if(connections[next] == 1) q.push(next);
        }
      }
      connections[u] = 0;
    }
    int ans = (half + 1) / 2;
    printf("Case #%d: %d\n", x++, ans);
  }
  return 0;
}
