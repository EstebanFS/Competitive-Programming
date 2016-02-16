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
const int MAXN = 10005;
typedef pair <int, int> edge; // Pareja (nodo, peso)
typedef pair <int, int> weight_node; // Pareja (peso, nodo)
vector <edge> g[MAXN]; // Lista de adyacencia
bool visited[MAXN];
int n, m;
// Retorna el costo total del MST

int prim(){ // n = numero de nodos
	for (int i = 0; i <= n; ++i) visited[i] = false;
	ll total = 0;
	priority_queue<weight_node, vector <weight_node>,
	greater<weight_node> > q;
	// Empezar el MST desde 0 (cambiar si el nodo 0 no existe)
	q.push(weight_node(0, 0));
	while (!q.empty()){
		int u = q.top().second;
		int w = q.top().first;
		q.pop();
		if (visited[u]) continue;
		visited[u] = true;
		total += w;
		for (int i = 0; i < g[u].size(); ++i){
			int v = g[u][i].first;
			int next_w = g[u][i].second;
			if (!visited[v]){
				q.push(weight_node(next_w, v));
			}
		}
	}
	return total;
}

void clean() {
	for(int i = 0; i <= n; ++i) g[i].clear();
}

int main() {
	while(cin >> n >> m && n) {
		map<string, int> cities;
		clean();
		for(int i = 0; i < n; ++i) {
			string name;
			cin >> name;
			cities[name] = i;
		}
		for(int i = 0; i < m; ++i) {
			string su, sv;
			int weight;
			cin >> su >> sv >> weight;
			int u = cities[su];
			int v = cities[sv];
			g[u].push_back(edge(v, weight));
			g[v].push_back(edge(u, weight));
		}
		string start;
		cin >> start;
		ll ans = prim();
		bool can = true;
		for(int i = 0; i < n; ++i) {
			if(!visited[i]) {
				can = false;
				break;
			}
		}
		if(can) cout << ans << endl;
		else cout << "Impossible" << endl;
	}
	return 0;
}
