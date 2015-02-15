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
#define ll long long
#define mli map<ll, int>

const ll MAXN = 10000000;
bool sieve[MAXN + 5];
//vector <int>  primes;
mli primes;
ll saves[MAXN + 5];

void build_sieve(){
	memset(sieve, false, sizeof(sieve));
	sieve[0] = sieve[1] = true;
	for (int i = 2; i * i <= MAXN; i ++){
		if (!sieve[i]){
			for (int j = i * i; j <= MAXN; j += i){
				sieve[j] = true;
			}
		}		
	}
	for (int i = 2; i <= MAXN; ++i){
		//if (!sieve[i]) primes.push_back(i);
		if (!sieve[i]) primes[i] = 1;
	}	
}

ll search_seive(ll x){
//	D(x);
//	int ans = 0;
//	for(int i = 0; i < primes.size(); ++i){
//		//D(primes[i]);
//		if(i > x)break;
//		if(x % primes[i] == 0){
//			ans++;
//			D(primes[i]);	
//		}
//	}
//	return ans;
	return primes.count(x);
}

ll divisors(ll n){
	if(saves[n] != -1) return saves[n];
	int i;
	ll ans = 0;
	if (!sieve[n]) return 1;
	for (i = 1; i * i < n; ++i){
		if (n % i == 0){
			ans += search_seive(i);
			ans += search_seive(n/i);	
		}
		//if (n % i == 0) printf("%d\n%d\n", i, n/i);
	}
	// Si existe, imprimir su raiz cuadrada una sola vez
	if (i * i == n) ans += search_seive(i);
	//if (i * i == n) printf("%d\n", i);
	saves[n] = ans;
	return ans;
}

int main(){
	build_sieve();
	memset(saves, -1, sizeof(saves));
	int n;
	int x = 1;
	cin >> n;
	while(n--){
		ll a, b, k;
		cin >> a >> b >> k;
		ll count = 0;
		//for(ll i = a; i <= b; ++i)if(search_seive(i) == k)count++;
		for(ll i = a; i <= b; ++i)if(divisors(i) == k)count++;
		printf("Case #%d: %d\n", x++, count);
	}
	return 0;
}




