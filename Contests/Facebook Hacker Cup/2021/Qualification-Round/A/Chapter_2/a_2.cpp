#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

#define ALPHA 30
#define D(x) cout << #x << " " << x << endl
#define INF 10000000

vector<int> g[ALPHA];

bool isConsistent(string &word) {
	bool consistent = true;
	for(int i = 1; i < word.size() && consistent; ++i) {
		if(word[i] != word[i - 1]) consistent = false;
	}
	return consistent;
}

vector<int> bfs(int start) {
	vector<int> d(ALPHA, -1);
	d[start] = 0;
	queue<int> q;
	q.push(start);
	while(!q.empty()) {
		int curr = q.front();
		q.pop();
		for(int i = 0; i < g[curr].size(); ++i) {
			int next = g[curr][i];
			if(d[next] == -1) {
				d[next] = d[curr] + 1;
				q.push(next);
			}
		}
	}
	return d;
}

void cleanGraph() {
	for(int i = 0; i < ALPHA; ++i) g[i].clear();
}

int main() {
	int t, m;
	string word, delta;
	cin >> t;
	for(int x = 1; x <= t; ++x) {
		cin >> word >> m;
		int ans = INF;
		vector<vector<int> > dist;
		cleanGraph();
		for(int i = 0; i < m; ++i) {
			cin >> delta;
			g[delta[0] - 'A'].push_back(delta[1] - 'A');
		}
		for(int i = 0; i < word.size(); ++i) {
			int currLetter = word[i] - 'A';
			dist.push_back(bfs(currLetter));
		}
		for(int i = 0; i < ALPHA; ++i) {
			bool can = true;
			int cost = 0;
			for(int j = 0; j < word.size() && can; ++j) {
				if(dist[j][i] == -1) can = false;
				else cost += dist[j][i];
			}
			if(can) ans = min(ans, cost);
		}
		if(ans == INF) printf("Case #%d: %d\n", x, -1);
		else printf("Case #%d: %d\n", x, ans);
	}
	return 0;
}
