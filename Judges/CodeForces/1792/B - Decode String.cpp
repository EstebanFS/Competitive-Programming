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
#include <bitset>

using namespace std;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int main() {
  int t, n;
  string number;
  cin >> t;
  while(t--) {
    cin >> n >> number;
    string decoded;
    for(int i = number.size() - 1; i >= 0; --i) {
      if(number[i] == '0') {
        string curr;
        curr += number[i - 2];
        curr += number[i - 1];
        int currN = toInt(curr) - 1;
        decoded += (char)(currN + 'a');
        i -= 2;
      } else {
        int currN = toInt(number[i]) - 1;
        decoded += (char)(currN + 'a');
      }
    }
    reverse(decoded.begin(), decoded.end());
    cout << decoded << endl;
  }
  return 0;
}
