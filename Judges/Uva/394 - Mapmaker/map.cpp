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
#define msv map<string, vector<int> >
#define msi map<string, int>

int main(){
	int n, r;
	cin >> n >> r;
	string name;
	int base, size, dim;
	msv arrays;
	msi dimen;
	for(int i = 0; i < n; ++i){
		cin >> name >> base >> size >> dim;
		vector<int> ci(dim + 1);
		pii di[dim];
		dimen[name] = dim;
		for(int x = 0; x < dim; ++x){
			int l, u;
			cin >> l >> u;
			di[x] = pii(l,u);
		}
		ci[dim] = size;
		for(int x = dim - 1; x >= 1; --x) ci[x] = ci[x + 1]*(di[x].second - di[x].first + 1);
		int baseC0 = 0;
		for(int x = 1; x <= dim; ++x) baseC0 -= ci[x]*di[x - 1].first;
		ci[0] = base + baseC0;
		arrays[name] = ci;

	}
	for(int i = 0; i < r; ++i){
		string name;
		cin >> name;
		int s = dimen[name];
		int result = arrays[name][0];
		int dii[s];
		for(int x = 0; x < s; ++x){
			cin >> dii[x];
			result += arrays[name][x + 1]*dii[x];
		}
		printf("%s[", name.c_str());
		for(int x = 0; x < s - 1; ++x) printf("%d, ",dii[x]);
		printf("%d] = %d\n",dii[s - 1], result);
	}
	return 0;
}




