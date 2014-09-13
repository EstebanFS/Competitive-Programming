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
#define MAXN 1005
#define MAXG 105
#define MAXP 35
#define ll long long

int v[MAXN];
int w[MAXN];
int dp[MAXN][MAXP];
int g[MAXG];

int main(){
    int cases; cin >> cases;
    for(int i=0; i<cases; i++){
        int nItems;cin>>nItems;
        for(int j=1; j<=nItems; j++)cin >> v[j] >> w[j];
        int ng; cin >> ng;
        for(int j=0; j<ng; j++)cin >>g[j]; 
        for(int j=0; j<MAXP; j++) dp[0][j] = 0;
        for(int j=1; j<=nItems; j++){
            for(int d=1; d<MAXP; d++){
                dp[j][d] = dp[j-1][d];
                if(d - w[j] >=0) dp[j][d] = max(dp[j][d],dp[j-1][d - w[j]] + v[j]);  
            } 
        } 
        ll ans=0;
        for(int j=0; j<ng; j++)ans += dp[nItems][g[j]];
        cout << ans << endl;
    }
	return 0;
}
