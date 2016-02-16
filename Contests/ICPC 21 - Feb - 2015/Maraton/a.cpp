using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
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


#define D(x) cout << #x " = " << (x) << endl

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str();}

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r;}

int n, m;

int main() {
	while (cin >> n >> m) {
		int ans = 0;
		vector <vector <int> > result;
		for (int i = 2; i <= n; i += 2) {
			vector <int> corners;
			corners.push_back(i);
			corners.push_back(1);
			corners.push_back(i);
			corners.push_back(m);
			ans++;
			result.push_back(corners);
		}
		for (int j = 2; j <= m; j += 2) {
			vector <int> corners;
			corners.push_back(1);
			corners.push_back(j);
			corners.push_back(n);
			corners.push_back(j);
			ans++;
			result.push_back(corners);
		}
		cout << ans << endl;
		for (int i = 0; i < result.size(); ++i) {
			cout << result[i][0];
			for (int j = 1; j < result[i].size(); ++j) {
				cout << " " << result[i][j];	
			}
			puts("");
		}
	}
	return 0;
}
