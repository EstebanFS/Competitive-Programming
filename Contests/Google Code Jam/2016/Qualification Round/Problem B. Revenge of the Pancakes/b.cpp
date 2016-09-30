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
#include <unordered_map>

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r;}

#define ll unsigned long long
#define D(x) cout << #x << " " << x << endl
#define MAXN 1050
int d[MAXN];

int convertToNumber(string x) {
  int result, curr = 2;
  if(x[0] == '+') result = 1;
  else result = 0;
  for(int i = 1; i < x.size(); ++i) {
    if(x[i] == '+') result += curr;
    curr *= 2;
  }
  return result;
}

char revert(char x) {
  if(x == '+') return '-';
  else return '+';
}

string slip(string x, int n) {
  string result;
  for(int i = 0; i < x.size(); ++i) {
    if(i <= n) result += revert(x[n - i]);
    else result += x[i];
  }
  return result;
}

int bfs(string x) {
  string endS;
  for(int i = 0; i < x.size(); ++i) endS += '+';
  int end = convertToNumber(endS), start = convertToNumber(x);
  if(end == start) return 0;
  for(int i = 0; i < end + 5; ++i) d[i] = -1;
  d[start] = 0;
  queue <string> q;
  q.push(x);
  while(!q.empty()) {
    string currS = q.front();
    q.pop();
    int curr = convertToNumber(currS);
    if(currS == endS) return d[curr];
    for(int i = 0; i < x.size(); ++i) {
      string nextS = slip(currS, i);
      int next = convertToNumber(nextS);
      if(d[next] == -1) {
        d[next] = d[curr] + 1;
        q.push(nextS);
      }
    }
  }
  return -1;
}



int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i) {
    string x;
    cin >> x;
    printf("Case #%d: %d\n", i + 1, bfs(x));
  }
	return 0;
}
