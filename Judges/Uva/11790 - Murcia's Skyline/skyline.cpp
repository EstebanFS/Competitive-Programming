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
#define MAX 10005
int heights[MAX];
int weights[MAX];
int dp[MAX];
int dp2[MAX];
int ans1,ans2;

int lis(int n){
   for(int i=0;i<n;i++){
      dp[i]= weights[i];
      dp2[i]=weights[i];
      for(int j=0; j<i; j++){
         if(heights[j] < heights[i])dp[i] = max(dp[i], dp[j]+weights[i]); 
         if(heights[i] < heights[j])dp2[i] = max(dp2[i], dp2[j]+weights[i]);  
      }  
   }
   int best=0,best2=0;
   for(int i=0;i<n; i++) best=max(best,dp[i]);
   for(int i=0;i<n; i++) best2=max(best2,dp2[i]);
   ans1 = best;
   ans2 = best2;
   return 0;  
}

int main(){
   int t,x=1; scanf("%d",&t);
   while(t--){
      int n; scanf("%d",&n);
      for(int i=0;i<n;i++)scanf("%d",&heights[i]);
      for(int i=0;i<n;i++)scanf("%d",&weights[i]);
      lis(n);
      if(ans1>=ans2)printf("Case %d. Increasing (%d). Decreasing (%d).\n",x++,ans1,ans2);
      else printf("Case %d. Decreasing (%d). Increasing (%d).\n",x++,ans2,ans1);
   }
	return 0;
}
