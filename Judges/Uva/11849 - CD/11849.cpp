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

#define mii map<int, int>


int main(){
  int n, m;
  while(cin >> n >> m) {
    if(n == 0 && m == 0) break;
    mii f;
    int cd;
    while(n--) {
      cin >> cd;
      f[cd]++;
    }
    while(m--) {
      cin >> cd;
      f[cd]++;
    }
    mii iterator :: it;
    int ans = 0;
    for(it = f.begin(); it != f.end(); ++it) if(it -> second == 2) ans++;
    cout << ans << endl;
  }
	return 0;
}
