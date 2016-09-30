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
#define MAXN 505
#define ll long long

int main(){
  int t;
  cin >> t;
  while(t--) {
    int presidents, countries;
    cin >> presidents >> countries;
    ll totalVotes[MAXN], total = 0;
    for(int i = 0; i < presidents; ++i) totalVotes[i] = 0;
    for(int i = 0; i < countries; ++i) {
      double votes[MAXN];
      for(int j = 0; j < presidents; ++j) cin >> votes[j];
      double votesCountry;
      cin >> votesCountry;
      total += votesCountry;
      for(int j = 0; j < presidents; ++j) totalVotes[j] += ((votes[j] * votesCountry) / 100.0);
    }

  }
	return 0;
}
