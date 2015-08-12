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
  int n;
  cin >> n;
  ll arr[n];
  for (int i = 0; i < n; ++i) cin >> arr[i];
  cout << abs(arr[0] - arr[1]) << " " << abs(arr[0] - arr[n - 1]) << endl;
  for(int i = 1; i < n - 1; ++i) {
    ll mini = min(abs(arr[i] - arr[i - 1]), abs(arr[i] - arr[i + 1]));
    ll maxi = max(abs(arr[i] - arr[0]), abs(arr[i] - arr[n - 1]));
    cout << mini << " " << maxi << endl;
  }
  cout << abs(arr[n - 1] - arr[n - 2]) << " " << abs(arr[n - 1] - arr[0]) << endl;
  return 0;
}
