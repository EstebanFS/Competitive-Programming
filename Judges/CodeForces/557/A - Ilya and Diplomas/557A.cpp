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
#define pii pair<int, int>
#define ll long long
int main() {
	int n;
	cin >> n;
	pii limits[3];
	int result[3];
	int base;
	for(int i = 0; i < 3; ++i){
		cin >> limits[i].first >> limits[i].second;
		result[i] = limits[i].first;
		base += limits[i].first;
	}
	n -= base;
	for(int i = 0; i < 3 && n > 0; ++i){
		int minimun = min(n, limits[i].second - limits[i].first);
		n -= minimun;
		result[i] += minimun;
	}
	for(int i = 0; i < 2; ++i) cout << result[i] << " ";
	cout << result[2] << endl;
	return 0;
}