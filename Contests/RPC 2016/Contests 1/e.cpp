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
#define MAXN 2000010
#define ll long long
ll roads[MAXN];

int main(){
	int t;
	cin >> t;
	while(t--) {
		int station;
		cin >> station;
		ll check = 0;
		for(int i = 0; i < station; ++i) {
			ll g, d;
			cin >> g >> d;
			roads[i] = g - d;
			roads[i + station] = g - d;
			check += (g - d);
		}
		ll sum = 0, ans = 0;
		int start = 0, end = 0, aux = 0;
		for(int i = 0; i < station * 2 && check >= 0; ++i) {
			sum += roads[i];
			if(sum < 0) {
				aux = i + 1;
				sum = 0;
			}
			if(sum > ans) {
				ans = sum;
				start = aux;
				end = i;
			}
		}
		if(check < 0) cout << "IMPOSSIBLE" << endl;
		else cout << start + 1 << endl;
	}
	return 0;
}
