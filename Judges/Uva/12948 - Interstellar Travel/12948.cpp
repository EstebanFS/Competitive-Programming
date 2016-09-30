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

#define D(x) cout << #x << " " << x << endl
#define MAXN 310
#define ll long long
#define pii pair <ll, ll>
#define piii pair <pii, ll>
#define psi pair <string, int>
#define INF 10000000000
vector <piii> g[MAXN];
map <string, int> planets;
pii d[MAXN][MAXN];

void bellmanFord(int start, int stops, int n) {
  for(int i = 0; i < n; ++i) d[0][i] = pii(INF, INF);
  d[0][start] = pii(0LL, 0LL);
  for(int x = 1; x <= stops; ++x) {
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < g[i].size(); ++j) {
        piii next = g[i][j];
        int nextNode = next.first.first;
        int cost = next.first.second;
        int t = next.second;
        pii aux = pii(d[x - 1][i].first + cost, d[x - 1][i].first + t);
        d[x][nextNode] = min(d[x - 1][nextNode], aux);
      }
    }
  }
}

int main(){
  int p, f, q;
  while(cin >> p >> f >> q) {
    for(int i = 0; i < p; ++i) {
      string name;
      cin >> name;
      planets[name] = i;
    }
    for(int i = 0; i < f; ++i) {
      int c, t;
      string x, y;
      cin >> x >> y >> c >> t;
      g[x].push_back(piii(pii(y, c), t));
    }
    string start;
    cin >> start;
    int valueStart = planets[start];
    vector <psi> queries;
    int minimunStops = MAXN;
    for(int i = 0; i < q; ++i) {
      string name;
      int stops;
      cin >> name >> stops;
      queries.push_back(psi(name, stops));
      minimunStops = min(minimunStops, stops + 1);
    }
    bellmanFord(valueStart, minimunStops, p);
    for(int i = 0; i < q; ++i) {
      string name = queries[i].first;
      int stops = queries[i].second;
      int nameValue = planets[name];
      printf("%d %d\n", d[stops][nameValue].first, d[stops][nameValue].second);
    }
  }
	return 0;
}
