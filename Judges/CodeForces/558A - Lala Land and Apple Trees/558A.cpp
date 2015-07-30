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

#define pii pair<int, int>

int main() {
	int n, sumn = 0, sump = 0;
	cin >> n;
	vector <pii> pos;
	vector <pii> neg;
	for(int i = 0; i < n; ++i){
		int coor, cant;
		cin >> coor >> cant;
		if(coor < 0){
			sumn += cant;
			neg.push_back(pii(coor, cant));
		} else {
			sump += cant;
			pos.push_back(pii(coor,cant));
		}
	}
	int ans = 0;
	int way;
	int side;
	if(pos.size() >= neg.size()){
		ans += sumn;
		way = min(neg.size() + 1, pos.size());
		side = 0;
		sort(pos.begin(), pos.end());
	}
	else {
		ans += sump;
		way = min(pos.size() + 1, neg.size());
		side = 1;
		sort(neg.rbegin(), neg.rend());
	}
	if(side == 0) for(int i = 0; i < way; ++i) ans += pos[i].second;
	else for(int i = 0; i < way; ++i) ans += neg[i].second;
	cout << ans << endl;
}