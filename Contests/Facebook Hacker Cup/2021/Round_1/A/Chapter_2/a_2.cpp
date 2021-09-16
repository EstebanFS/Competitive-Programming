#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

#define ALPHA 30
#define INF 1000.0
#define pcc pair<char, char>
#define D(x) cout << #x << " " << x << endl
#define MAXN 800005
#define MOD 1000000007
#define vi vector<int>
#define matrix vector<vi>
#define pbm pair<bool, matrix>


pbm generateRoutes(int n, int m, int x, int y) {
  matrix tmp = matrix(n, vi(m, 1));
  tmp[0][0] = x - m - n + 2;
  tmp[n - 1][0] = y - m - n + 2;
  pbm ans = pbm(tmp[0][0] > 0 && tmp[n - 1][0] > 0, tmp);
  return ans;
}

int main() {
	int t, n, m, first, second;
	string word;
	cin >> t;
	for(int x = 1; x <= t; ++x) {
		cin >> n >> m >> first >> second;
		pbm ans = generateRoutes(n, m, first, second);
		if(!ans.first) printf("Case #%d: %s\n", x, "Impossible");
		else {
      matrix tmp = ans.second;
      printf("Case #%d: %s\n", x, "Possible");
  		for(int i = 0; i < tmp.size(); ++i) {
  			cout << tmp[i][0];
  			for(int j = 1; j < tmp[0].size(); ++j) cout << " " << tmp[i][j];
  			cout << endl;
  		}
    }
	}
	return 0;
}
