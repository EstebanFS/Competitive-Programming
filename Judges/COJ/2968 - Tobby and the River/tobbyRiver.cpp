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
int dogs[6];

bool
possible(int nDogs, int boat1, int boat2) {
  if (nDogs == 6) return boat1 == boat2;
  int next = dogs[nDogs];
  return possible(nDogs+1, boat1 + next, boat2) |
         possible(nDogs+1, boat1, boat2 + next);
}

int
main() {
  int t;cin >> t;
  while (t--) {
    for (int i = 0; i < 6; i++) cin >> dogs[i];
    if (possible(0, 0, 0)) puts("Tobby puede cruzar");
    else puts("Tobby no puede cruzar");
  }
  return 0;
}
