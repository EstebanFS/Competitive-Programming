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
   int tbeds;
   while(cin>>tbeds){
      if(tbeds==0)break;
      set <char> users;
      string list;cin>>list;
      int ans=0;
      for(int i=0;i<list.size();i++){
         int usize = users.size();     
         users.insert(list[i]);
         if(usize<users.size()){
            if(users.size()>tbeds){
               ans++;
               users.erase(list[i]);  
            }  
         }else users.erase(list[i]);
      }
      ans/=2;
      if(ans==0)printf("All customers tanned successfully.\n");
      else printf("%d customer(s) walked away.\n",ans);
   }
	return 0;
}
