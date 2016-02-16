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
#define MAXN 32

ll ans[MAXN];

void build() {
	ans[0] = 0;
	ans[1] = 1;
	for(int i = 2; i < MAXN; ++i) ans[i] = ans[i - 1] * 2 + 1;
}

int main() {
	int t;
	cin >> t;
	build();
	while(t--) {
		int n;
		cin >> n;
		cout << ans[n] << endl;	
	}
	return 0;
}

