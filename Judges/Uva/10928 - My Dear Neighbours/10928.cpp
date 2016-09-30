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

#define MAXN 1005
int hood[MAXN];

int main(){
  int t;
  cin >> t;
  string trash;
  getline(cin, trash);
  while(t --) {
    int n;
    cin >> n;
    getline(cin, trash);
    int mini = 100000000;
    for(int i = 0; i < n; ++i){
      string line;
      getline(cin, line);
      stringstream buffer;
      buffer << line;
      int aux;
      hood[i] = 0;
      while(buffer >> aux) hood[i]++;
      mini = min(hood[i], mini);
    }
    bool first = true;
    for(int i = 0; i < n; ++i) {
      if(hood[i] == mini && first) {
        cout << i + 1;
        first = false;
      } else if(hood[i] == mini && !first) cout << " " << i + 1;
    }
    cout << endl;
  }
  return 0;
}
