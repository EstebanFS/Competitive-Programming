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
#define MAX 5005

int dp[MAX][MAX];

int main(){
    string s,t;
    int a,b;
    while(cin>>a>>s >>b >>t){
       for(int i=0;i<=s.size();i++)dp[i][0]=i;
       for(int i=0;i<=t.size();i++)dp[0][i]=i;
       
       for(int i=1; i<=s.size();i++){
               for(int j=1; j<=t.size(); j++){
                       if(s[i-1]==t[j-1])dp[i][j]=dp[i-1][j-1];
                       else dp[i][j]= min(min((1+dp[i-1][j-1]),1+dp[i-1][j]),1+dp[i][j-1]);     
               }     
       }
       cout << dp[s.size()][t.size()] << endl;
   }
}
