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
#define pci pair<char, int>
char up = '/';
char down = '\\';
stack <pci> city;

int clearStack(){
   while(!city.empty())city.pop();
   return 0;
}

int main(){
   int t; cin >> t;
   getchar();
   while(t--){
      clearStack();
      string line;
      getline(cin,line);
      int ans =0;
      for(int i=0;i<line.size();i++){
         if(line[i]=='\\')city.push(make_pair(down,i));
         else if(line[i]=='/'){
            if((!city.empty())&&(city.top().first==down)){
               int a = city.top().second;
               ans+=(i-a);
               city.pop();   
            }  
         }     
      }
      cout << ans << endl;
   }
	return 0;
}
