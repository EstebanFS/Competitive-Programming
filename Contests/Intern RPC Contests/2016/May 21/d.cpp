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
#define MAXN 100005
#define ll long long

ll solve(ll n) {
  ll term = 1;
  int terms[4];
  for(int i = 0; i < 4; ++i) {
    terms[i] = term * n;
    term = terms[i];
  }
  return (terms[3] - (terms[2] * 6) + (terms[1] * 23) - (terms[0] * 18) + 24) / 24;
}

int main(){
  int t;
  cin >> t;
  while(t--) {
    ll n;
    cin >> n;
    cout << solve(n) << endl;
  }
	return 0;
}
