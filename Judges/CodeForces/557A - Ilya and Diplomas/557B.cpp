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

#define ll long long

int main() {
	ll guest, boil;
	cin >> guest >> boil;
	ll party[guest * 2];
	for(int i = 0; i < guest * 2; ++i) cin >> party[i];
		sort(party, party + (guest * 2));
		double base;
		if(party[0] * 2 > party[guest]) base = (double)party[guest]/2.0;
		else base = (double)party[0];
		double total = (base * (double)guest) + (base * 2.0 * (double)guest);
		if (total <= boil) printf("%.9lf\n", total);
		else printf("%.9lf\n", boil * 1.0);
		return 0;
	}
