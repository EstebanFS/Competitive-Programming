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
#define MAX 305
#define MAXC 45
# define INF 1000000

int dp[MAX][MAX];
int coins[MAXC];
int ecoins[MAXC];

int fill(int s){
   for(int i=0;i<=s;i++)
      for(int j=0;j<=s;j++)dp[i][j]=INF;
   return 0;
}

int main(){
   int t;cin >> t;
   while(t--){
      int n,s;cin>>n>>s;
      for(int i=0;i<n;i++)cin>>coins[i]>>ecoins[i];
      fill(s);
      dp[0][0]=0;
      for(int i=0;i<n;i++)
         for(int j=coins[i];j<=s;j++)
            for(int k=ecoins[i];k<=s;k++)
               dp[j][k]= min(dp[j][k], dp[j-coins[i]][k-ecoins[i]]+1);
      
      int ans = INF;
      int sdouble = s*s;
      for(int i=0;i<=s;i++)
         for(int j=0;j<=s;j++)
            if((i*i + j*j)==sdouble)ans = min(ans,dp[i][j]);
      if(ans==INF)cout<< "not possible" << endl;
      else cout << ans << endl;  
      
   }
	return 0;
}
