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
#define msi map <string, int>

int main() {
  int n;
  cin >> n;
  int sum = 0;
  for(int i = 0; i < n; ++i) {
    int x, y, x2, y2;
    cin >> x >> y >> x2 >> y2;
    sum += abs(x2 - x + 1) * abs(y2 - y + 1);
  }
  cout << sum << endl;
  return 0;
}
