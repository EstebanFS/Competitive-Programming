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

int n;

int moveGear(int direction, int initial, int final){
  if(direction > 0) {
    if(initial <= final) return (final - initial);
    else return ((n - initial) + final);
  } else {
    if(initial >= final) return (initial - final);
    else return (initial + (n - final));
  }
  return 0;
}

int main(){
  cin >> n;
  bool can = true;
  int gear;
  cin >> gear;
  int diff = moveGear(1, gear, 0);
  int movement = 1;
  for(int i = 1; i < n; ++i){
    cin >> gear;
    movement *= -1;
    if(diff != moveGear(movement, gear, i)) can = false;
  }
  if(can) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
