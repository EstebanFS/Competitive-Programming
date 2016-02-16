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

int main() {
	int n;
	while(cin >> n){
		priority_queue<int, vector<int>, greater<int> > q;
		for(int i = 0; i < n; ++i) {
			int fl;
			cin >> fl;
			q.push(fl);
		}
		int ans = n;
		while(!q.empty()) {
			int fl = q.top();
			q.pop();
			int aux = fl + q.size();
			ans = min(ans, aux);
		}
		cout << ans << endl;
	}
	return 0;
}

