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

#define ll long long
#define D(x) cout << #x << " " << x << endl
#define MAXN 30
#define pii pair <int, int>
int f[MAXN];
string numbers[MAXN];


void countF(string x) {
  for(int i = 0; i < MAXN; ++i) f[i] = 0;
  for(int i = 0; i < x.size(); ++i) f[x[i] - 'A']++;
}

bool compareNumber(string x) {
  int fAux[MAXN];
  for(int i = 0; i < MAXN; ++i) fAux[i] = 0;
  for(int i = 0; i < x.size(); ++i) fAux[x[i] - 'A']++;
  for(int i = 0; i < MAXN; ++i) if(f[i] < fAux[i]) return false;
  for(int i = 0; i < MAXN; ++i) f[i] -= fAux[i];
  return true;
}

void createN() {
  numbers[0] = "ZERO";
  numbers[1] = "ONE";
  numbers[2] = "TWO";
  numbers[3] = "THREE";
  numbers[4] = "FOUR";
  numbers[5] = "FIVE";
  numbers[6] = "SIX";
  numbers[7] = "SEVEN";
  numbers[8] = "EIGHT";
  numbers[9] = "NINE";
}

string solve() {
  int x = 0;
  string ans;
  while(x <= 9) {
    string curr = numbers[x];
    bool can = compareNumber(curr);
    if(can) ans += toStr(x);
    else x++;
  }
  return ans;
}

int main(){
  createN();
  int n;
  cin >> n;
  for(int i = 1; i <= n; ++i) {
    string s;
    cin >> s;
    countF(s);
    printf("Case #%d: %s\n", i, solve().c_str());
  }
	return 0;
}
