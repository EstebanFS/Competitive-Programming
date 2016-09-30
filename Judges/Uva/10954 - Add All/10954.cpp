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

int main(){
  int n;
  while(cin >> n && n) {
    priority_queue <int, vector <int>, greater <int> > q;
    while(n --) {
      int curr;
      cin >> curr;
      q.push(curr);
    }
    ll cost = 0;
    while(q.size() > 1) {
      int first = q.top();
      q.pop();
      int second = q.top();
      q.pop();
      cost += (first + second);
      q.push(first + second);
    }
    cout << cost << endl;
  }
	return 0;
}
