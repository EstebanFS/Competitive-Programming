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
#define MAXN 105
#define INF 1000000
int d[MAXN][MAXN];

int floyd_warshall(int n){
    for(int k=0; k < n; k++){
        for(int i=0; i < n; ++i){
            for(int j=0; j < n; ++j){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    return 0;
}

int clean(int n){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(i==j)d[i][j]=0;
            else d[i][j]=INF;   
        }
    }
}

int main(){
    int cases;
    cin >> cases;
    while(cases--){
        int n,e,t,m;
        cin >> n >> e >> t >> m;
        clean(n);
        for(int i=0; i<m; i++){
            int u,v,w;
            cin >> u >> v >> w;
            u--;v--;
            if(u==v)d[u][v]=0;
            else d[u][v]=w;    
        }
        floyd_warshall(n);
        e--;
        int ans =0;
        for(int i=0; i<n; i++)if(d[i][e]<=t)ans++;
        cout << ans << endl;
        if(cases!=0)cout << endl;;
    }
	return 0;
}


