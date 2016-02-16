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

int main(){
   int cases;
   while(cin>>cases){
      if(cases==0)break;
      int ans=0;
      for(int i=0;i<cases;i++){
         int count=0;
         for(int j=0;j<5;j++){
            int n;cin>>n;
            if(n>=10)count++;      
         }
         if(count>=3)ans++;  
      }
      cout << ans << endl;  
   }
	return 0;
}
