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
const ll MAXN = 1111111111111111;
bool sieve[MAXN + 5];
vector <ll> primes;

void build_sieve(){
  memset(sieve, false, sizeof(sieve));
  sieve[0] = sieve[1] = true;
  for (ll i = 2; i * i <= MAXN; i ++){
    if (!sieve[i]){
      for (ll j = i * i; j <= MAXN; j += i){
        sieve[j] = true;
      }
    }
  }
  for (ll i = 2; i <= MAXN; ++i){
    if (!sieve[i]) primes.push_back(i);
  }
}

ll convertToBase(string x, int b) {
  ll result;
  if(x[x.size() - 1] == '1') result = 1LL;
  else result = 0LL;
  ll acum = (ll)b;
  for(int i = 0; i < x.size() - 1; ++i) {
    if(x[i] == '1') result += acum;
    acum *= b;
  }
  return result;
}


int main(){
  //build_sieve();
	return 0;
}
