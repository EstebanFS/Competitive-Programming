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
	int t, n;
	cin >> t;
	while (t--){
		cin >> n;
		int cities[n];
		ll sum[n];
		for (int i = 0; i < n; ++i) cin >> cities[i];
		sum[0] = cities[0];
		for (int i = 1; i < n; ++i) sum[i] = sum[i-1] + cities[i];
		ll total = sum[n-1];
		ll maxi = total;
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < (n-i); ++j){
				ll depreciate = sum[j+i];
				ll rest;
				if ((j-1) < 0) rest = 0;
				else rest = sum[j-1]; 
				//printf ("El depreciate es: %d, el rest es: %d y el total es: %d\n", depreciate, rest, total);
				maxi = max(maxi, total - depreciate + rest);
			}
		}
		cout << maxi << endl;
	}
	return 0;
}




