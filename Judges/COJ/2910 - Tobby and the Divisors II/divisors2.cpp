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
#define MAX 1000001

int divisors[MAX];

int makeDivisors(){
   for(int x=2;x<=MAX;x++){
      divisors[x]++;
      for(int i=x;i<=MAX;i+=x)divisors[i]++;
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
