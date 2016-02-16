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
#define MAXN 10005

vector<int> g[MAXN];
int d[MAXN];
bool fall[MAXN];
int n, m, l;
int ans;

void dfs(int s){
	ans++;
	fall[s] = true;
	for(int i = 0; i < g[s].size(); ++i) {
		int next = g[s][i];
		if(!fall[next]) dfs(next);
	}	
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> m >> l;
		for(int i = 0; i <= n; ++i) {
			fall[i] = false;
			g[i].clear();
		}
		ans = 0;
		for(int i = 0; i < m; ++i) {
			int x, y;
			cin >> x >> y;
			x--; y--;
			g[x].push_back(y);
		}
		for(int i = 0; i < l; ++i) {
			int start;
			cin >> start;
			start--;
			if(!fall[start]) dfs(start);
		}
		cout << ans << endl;
	}
	return 0;
}

