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
  string numbers;
  cin >> n >> numbers;
  int countOne = 0, countZero = 0;
  for(int i = 0; i < n; ++i) {
    if(numbers[i] == '1') countOne ++;
    else countZero ++;
  }
  cout << abs(countOne - countZero) << endl;
  return 0;
}
