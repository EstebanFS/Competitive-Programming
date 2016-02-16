#include <bits/stdc++.h>

using namespace std;

const int MAXN = 505;
vector <int> gCat[MAXN];
vector <int> gMouse[MAXN];
int t, n, sCat, sMouse;
int dCat[MAXN];
int color[MAXN];
enum {WHITE, GRAY, BLACK};
string line;
bool ans1, ans2;

void
bfsCat(int s) {
  for (int i = 0; i <= n; ++i) dCat[i] = -1;
  queue <int> q;
  q.push(s);
  dCat[s] = 0;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int i = 0; i < gCat[cur].size(); ++i) {
      int next = gCat[cur][i];
      if (dCat[next] == -1) {
        dCat[next] = dCat[cur] + 1;
        q.push(next); 
      }
    }
  }
}

void dfs(int u) {
  color[u] = GRAY;
  if (dCat[u] != -1) {
    ans1 = true;
    return;
  }
  for (int i = 0; i < gMouse[u].size(); ++i) {
    int v = gMouse[u][i];
    if (v == sMouse && color[v] == GRAY) {
      ans2 = true;
      //return;
    }
    if (color[v] == WHITE) dfs(v);
  }
  color[u] = BLACK;
}

int
main() {
  cin >> t;
  cin.ignore();
  getline(cin, line);
  while (t--) {
    ans1 = false;
    ans2 = false;
    cin >> n >> sCat >> sMouse;
    for (int i = 0; i <= n; ++i) {
      gCat[i].clear();
      gMouse[i].clear(); 
    }
    cin.ignore();
    bool readingCat = true;
    while (getline(cin, line)) {
      stringstream ss(line);
      int a, b;
      if (readingCat) {
        ss >> a >> b;
        if (a == -1 && b == -1) {
          readingCat = false;
          continue;
        }
        gCat[a].push_back(b);
      }
      else {
        if (line.size() == 0) break;
        ss >> a >> b;
        gMouse[a].push_back(b);
      }
    }
    
    //Bfs cat
    bfsCat(sCat);
    
    for (int i = 0; i <= n; ++i) color[i] = WHITE;
    dfs(sMouse);
    printf("%s %s\n", ans1 ? "Y" : "N", ans2 ? "Y" : "N");
    if (t) puts("");
  }
  return 0;
}

