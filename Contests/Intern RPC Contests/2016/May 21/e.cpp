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

int main(){
	int t, M, W;
  cin >> t;
  int elephants[MAXN];
  while(t--) {
    cin >> M >> W;
    for(int i = 0; i < M; ++i) cin >> elephants[i];
    sort(elephants, elephants + M);
    int sum = 0, i;
    for(i = 0; i < M && sum <= W; ++i) sum += elephants[i];
    if(sum > W) i--;
    cout << i << endl;
  }
	return 0;
}
