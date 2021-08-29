#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <set>

using namespace std;

#define pii pair<int, int>
#define INF 1000000
#define MAXN 100

pii canWin(vector<string> m) {
	int minMovements = INF;
	vector<set<vector<pii> > > ways(MAXN);
	for(int i = 0; i < m.size(); ++i) {
		bool can = m[i][0] != 'O';
		vector<pii> movements;
		if(m[i][0] == '.') movements.push_back(pii(i, 0));
		for(int j = 1; j < m[0].size() && can; ++j) {
			if(m[i][j] == 'O') can = false;
			else if(m[i][j] == 'X') continue;
			movements.push_back(pii(i, j));
		}
		if(can) {
			minMovements = min(minMovements, (int)movements.size());
			ways[movements.size()].insert(movements);
		}
	}
	for(int i = 0; i < m[0].size(); ++i) {
		bool can = m[0][i] != 'O';
		vector<pii> movements;
		if(m[0][i] == '.') movements.push_back(pii(0, i));
		for(int j = 1; j < m.size() && can; ++j) {
			if(m[j][i] == 'O') can = false;
			else if(m[j][i] == 'X') continue;
			movements.push_back(pii(j, i));
		}
		if(can) {
			minMovements = min(minMovements, (int)movements.size());
			ways[movements.size()].insert(movements);
		}
	}
	pii ans;
	if(minMovements == INF) ans = pii(-1, -1);
	else ans = pii(minMovements, ways[minMovements].size());
	return ans;
}

int main() {
	int t, n;
	cin >> t;
	for(int x = 1; x <= t; ++x) {
		cin >> n;
		vector<string> m(n);
		for(int i = 0; i < n; ++i) cin >> m[i];
		pii ans = canWin(m);
		if(ans.first == -1) printf("Case #%d: Impossible\n", x);
		else printf("Case #%d: %d %d\n", x, ans.first, ans.second);
	}
	return 0;
}
