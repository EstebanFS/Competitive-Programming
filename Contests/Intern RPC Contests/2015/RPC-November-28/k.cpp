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

#define ll long long
#define D(x) cout << #x << " " << x << endl;
#define MAXN 40
vector <int> g[MAXN];
int d[MAXN];
int p[MAXN];
map<string, int> m;
map<int, string> convert;

void bfs(int u) {
  for(int i = 0; i < MAXN; ++i) d[i] = -1;
  d[u] = 0;
  p[u] = -1;
  queue<int> q;
  q.push(u);
  while(!q.empty()) {
    int v = q.front();
    q.pop();
    for(int i = 0; i < g[v].size(); ++i) {
      int next = g[v][i];
      //printf("Connection %s to %s\n", convert[v].c_str(), convert[next].c_str());
      if(d[next] == -1) {
        d[next] = d[v] + 1;
        p[next] = v;
        q.push(next);
      }
    }
  }
}

int main() {
  int n;
  cin >> n;
  getchar();
  int curr = 0;
  while(n--) {
    string line, x, y;
    getline(cin, line);
    stringstream ss;
    ss << line;
    ss >> x;
    if(!m.count(x)) {
      m[x] = curr;
      convert[curr] = x;
      curr++;
    }
    while(ss >> y) {
      if(!m.count(y)) {
        m[y] = curr;
        convert[curr] = y;
        curr++;
      }
      g[m[x]].push_back(m[y]);
      g[m[y]].push_back(m[x]);
    }
  }
  string start, destination;
  cin >> start >> destination;
  bfs(m[start]);
  int v = m[destination];
  if(d[v] != -1) {
    vector <string> ans;
    while(p[v] != -1) {
    	ans.push_back(convert[v]);
    	v = p[v];
    }
    cout << start;
    for(int i = ans.size() - 1; i >= 0; --i) cout << " " << ans[i];
    cout << endl;
  } else {
    cout << "no route found" << endl;
  }
}
