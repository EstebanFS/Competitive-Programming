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



int main() {
	int n;
	cin >> n;
	int medals[n];
	for(int i = 0; i < n; ++i) cin >> medals[i];
	sort(medals, medals + n);
	int ans = 0;
	for(int i = 1; i < n; ++i){
			if(medals[i] <= medals[i - 1]) {
				ans += abs(medals[i] - medals[i - 1]) + 1;
				medals[i] = medals[i - 1] + 1;
			}
	}
	cout << ans << endl;
	return 0;
}
