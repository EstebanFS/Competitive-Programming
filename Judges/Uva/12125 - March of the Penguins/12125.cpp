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
#define D(x) cout << #x " is " << x << endl
#define MAXN 105
#define INF 500

struct point {
    double x;
    double y;
    point(const int _x, const int _y) {
      x = _x;
      y = _y;
    }
};

vector<point> points;
int peng[MAXN], jumpT[MAXN], numberOfP;
double maxDistance;
vector <int> g[MAXN];
int c[MAXN][MAXN];
int fl[MAXN][MAXN];
int totalOfPeng = 0;
int prevNode[MAXN];
inline double f(point firstp, point secondp) {return sqrt((firstp.x - secondp.x) * (firstp.x - secondp.x) + (firstp.y - secondp.y) * (firstp.y - secondp.y));}
inline int primeNode(int i) {return i + numberOfP;}

void connect() {
  for(int i = 0; i < numberOfP; ++i) {
    int x, y, p, t;
    cin >> x >> y >> p >> t;
    point pi(x, y);
    points.push_back(pi);
    peng[i] = p;
    jumpT[i] = t;
    totalOfPeng += p;
  }
  for(int i = 0; i < points.size(); ++i) {
    for(int j = i + 1; j < points.size(); ++j) {
      if(f(points[i], points[j]) <= maxDistance) {
        g[primeNode(i + 1)].push_back(j + 1);
        g[primeNode(j + 1)].push_back(i + 1);
        c[primeNode(i + 1)][j + 1] = INF;
        c[primeNode(j + 1)][i + 1] = INF;
      }
    }
  }
  //Connect source with nodes
  for(int i = 1; i <= numberOfP; ++i) {
    g[0].push_back(i);
    c[0][i] = peng[i];
  }
  //Connect node with nodePrime
  for(int i = 1; i <= numberOfP; ++i) {
    g[i].push_back(primeNode(i));
    c[i][primeNode(i)] = jumpT[i];
  }
}

int
maxflow(int s, int t, int n){
  for(int i = 0; i <= numberOfP; ++i) {
    for(int j = 0; j <= numberOfP; ++j) {
      fl[i][j] = 0;
    }
  }
  int flow = 0;
  while(true) {
    for(int i = 0; i <= n; ++i) prevNode[i] = -1;
    queue <int> q;
    q.push(s);
    prevNode[s] = -2;
    while(q.size() > 0) {
      int u = q.front(); q.pop();
      if(u == t) break;
      for(int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if(prevNode[v] == -1 && c[u][v] - fl[u][v] > 0) {
          q.push(v);
          prevNode[v] = u;
        }
      }
    }
    if(prevNode[t] == -1) break;
    int extra = 1 << 30;
    int end = t;
    while(end != s) {
      int start = prevNode[end];
      extra = min(extra, c[start][end] - fl[start][end]);
      end = start;
    }
    end = t;
    while(end != s) {
      int start = prevNode[end];
      fl[start][end] += extra;
      fl[end][start] = -fl[start][end];
      end = start;
    }
    flow += extra;
  }
  return flow;
}

int main() {
  int n;
  cin >> n;
  while(n--) {
    cin >> numberOfP >> maxDistance;
    connect();
    vector <int> ans;
    for(int i = 1; i <= numberOfP; ++i) {
      int possible = maxflow(0, i, numberOfP);
      D(possible);
      if(possible == totalOfPeng) ans.push_back(i - 1);
    }
    if(ans.size() == 0) cout << -1 << endl;
    else {
      cout << ans[0];
      for(int i = 1; i < ans.size(); ++i) cout << " " << ans[i];
      cout << endl;
    }
  }
  return 0;
}
