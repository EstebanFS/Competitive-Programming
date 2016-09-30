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
#define MAXN 30
int sodu[MAXN][MAXN];

bool solve(int s) {
	bool can = true, f[10];
	for(int i = 0; i < s && can; ++i) {
		for(int z = 0; z < 10; ++z) f[z] = false;
		for(int j = 0; j < s && can; ++j) {
			int curr = sodu[i][j];
			if(f[curr]) can = false;
			else f[curr] = true;
		}
	}
	for(int i = 0; i < s && can; ++i) {
		for(int z = 0; z < 10; ++z) f[z] = false;
		for(int j = 0; j < s && can; ++j) {
			int curr = sodu[j][i];
			if(f[curr]) can = false;
			else f[curr] = true;
		}
	}
	for(int i = 0; i < s && can; ++i) {
		for(int j = 0; j < s && can; ++j) {
			for(int z = 0; z < 10; ++z) f[z] = false;
			for(int x = 0; x * x < s && can; ++x) {
				for(int y = 0; y * y < s && can; ++y) {
					int curr = sodu[i + x][j + y];
					if(f[curr]) can = false;
					else f[curr] = true;
				}
			}
			j += (sqrt(s) - 1);
		}
		i += (sqrt(s) - 1);
	}
	return can;
}

int main(){
	int t, s;
	cin >> t;
	while(t--) {
		cin >> s;
		for(int i = 0; i < s; ++i) {
			for(int j = 0; j < s; ++j) cin >> sodu[i][j];
		}
		if(solve(s)) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}
