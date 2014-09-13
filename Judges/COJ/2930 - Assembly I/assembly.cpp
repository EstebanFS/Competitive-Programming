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
#define MAX 1001
int dp[MAX],dp2[MAX],accep[MAX],incre,decre;

int lis(int n){
   dp[0]= 1;
   dp2[0]=1;
   for(int i=1;i<n;i++){
      dp[i]= 1;
      dp2[i]=1;
      for(int j=0; j<i; j++){
         if(accep[j] < accep[i])dp[i] = max(dp[i], dp[j]+1); 
         if(accep[i] < accep[j])dp2[i] = max(dp2[i], dp2[j]+1);  
      }  
   }
   int bestIncre=0,bestDecre=0;
   for(int i=0;i<n; i++) bestIncre=max(bestIncre,dp[i]);
   for(int i=0;i<n; i++) bestDecre=max(bestDecre,dp2[i]);
   incre = bestIncre;
   decre = bestDecre;
   return 0;  
}


int main(){
   int t;
   while(cin>>t){
      for(int i=0;i<t;i++)cin>>accep[i];
      lis(t);
      if(incre==decre)cout<<"Caution. I will not intervene."<<endl;
      else cout<<"Don't worry. I must intervene." <<endl;  
   }
	return 0;
}
