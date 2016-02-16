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

int main(){
	ll n, t;
	cin >> n >> t;
	ll transport[n];
	for(ll i = 0; i < n; ++i) cin >> transport[i];
	bool can = false;
	ll i = 0;
	while(i <= (t-1)){
	//	cout << "Entra" << endl;
		if(i == (t-1)) {
			can = true;
			break;
		}
		i += transport[i];
	}
	if(can) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}




