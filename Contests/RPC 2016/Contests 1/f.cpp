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

#define D(x) cout << #x << " " << x << endl;
#define MAXN 105
int n, m, p, c, totalNodes;
bool visited[MAXN * MAXN];
vector<int> g[MAXN * MAXN];

void dfs(int u) {
	visited[u] = true;
	for(int i = 0; i < g[u].size(); ++i) {
		int next = g[u][i];
		if(!visited[next]) {
			totalNodes--;
			dfs(next);
		}
	}
}

void clean() {
	for(int i = 0; i < MAXN * MAXN; ++i) g[i].clear();
}


int main(){
	int t;
	cin >> t;
	int desc[MAXN][MAXN];
	int node = 0;
	for(int i = 0; i < MAXN; ++i) {
		for(int j = 0; j < MAXN; ++j) {
			desc[i][j] = node;
			node++;
		}
	}
	while(t--) {
		clean();
		cin >> n >> m >> p >> c;
		totalNodes = m * n;
		queue<int> generators, nodes;
		memset(visited, false, MAXN * MAXN);
		for(int i = 0; i < p; ++i) {
			int x, y;
			cin >> x >> y;
			int gen = desc[x][y];
			visited[gen] = true;
			totalNodes--;
			generators.push(gen);
		}
		for(int i = 0; i < c; ++i) {
			int x, y;
			char move;
			cin >> x >> y >> move;
			int curr = desc[x][y];
			int next;
			if(move == 'U') next = desc[x][y + 1];
			else next = desc[x + 1][y];
			nodes.push(curr);
			g[curr].push_back(next);
			g[next].push_back(curr);
		}
		while(!generators.empty()) {
			int curr = generators.front();
			generators.pop();
			dfs(curr);
		}
		while(!nodes.empty()) {
			int curr = nodes.front();
			nodes.pop();
			dfs(curr);
		}
		cout << totalNodes << endl;
	}
	return 0;
}
