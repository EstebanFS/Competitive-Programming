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
#define MAX 2501

int divisors[MAX];

int makeDivisors(){
   for(int x=1;x<=MAX;x++){
      int i,ans=0;
      for(i=1; i*i<x;++i){
         if(x%i==0)ans+=2;
      }
      if(i*i==x)ans++;
      divisors[x]=ans; 
   }      
   return 0;  
}

int main(){
   int t;cin>>t;
   makeDivisors();
   while(t--){
      int number;cin>>number;
      int ans=number;
      for(int i=number;i>=1;i--){
         if(divisors[i]>divisors[ans])ans=i;
         if(divisors[i]==divisors[ans])ans=min(ans,i);       
      }
      cout<<ans<<endl;
   }
	return 0;
}
