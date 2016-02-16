//Santiago Vanegas Gil.
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>

using namespace std;

const int MAXN = 105;
int n, m, q;
map <string, int> mid;
int d[MAXN];
vector <int> g[MAXN];

void
bfs(int s) {
  for (int i = 0; i <= n; i++) d[i] = -1;
  queue <int> q;
  q.push(s);
  d[s] = 0;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int i = 0; i < g[cur].size(); ++i) {
      int next = g[cur][i];
      if (d[next] == -1) {
        d[next] = d[cur] + 1;
        q.push(next); 
      } 
    } 
  } 
}

int
main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string name;
    cin >> name;
    mid[name] = i;
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    string name1, name2;
    cin >> name1 >> name2;
    g[mid[name1]].push_back(mid[name2]);
    g[mid[name2]].push_back(mid[name1]);
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    string name1, name2;
    cin >> name1 >> name2;
    bfs(mid[name1]);
    int index2 = mid[name2];
    if (d[index2] != -1 && d[index2] <= 6) cout << "Aceptada" << endl;
    else cout << "Rechazada" << endl;
  }
  return 0;
}
