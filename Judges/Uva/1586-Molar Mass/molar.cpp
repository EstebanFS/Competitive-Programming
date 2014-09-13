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
map <char, double> organic;


int makeOrganic(){
   organic['C']=12.01;
   organic['H']=1.008;
   organic['O']=16.00;
   organic['N']=14.01;
   return 0;
}

int main(){
   makeOrganic();
   int cases;cin>>cases;
   while(cases--){
      string comp;cin>>comp;
      string sub="";
      double ans=0;
      for(int i=comp.size()-1;i>=0;i--){
         if(comp[i]>=65&&comp[i]<=90){
            int nsub=0;
            if(sub.size()==0)nsub=1;
            else nsub=toInt(sub);
            ans+=(organic[comp[i]]*nsub);
            sub="";  
         }else sub=comp[i]+sub; 
      }
      printf("%.3f\n",ans); 
   }
	return 0;
}
