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
#define MAXN 50005
int p[MAXN];

void initialize(int n){
   for(int i=0; i<=n ; i++)p[i]=i;   
}

int find(int u){
   if(p[u]==u)return u;
   return p[u] = find(p[u]);  
}

void join(int u,int v){
   int a=find(u);
   int b=find(v);
   if(a==b)return;
   p[a]=b;
}

int main(){
   int n,m,x=1;
   while(cin >> n >> m){
      if(n==0&&m==0)break;
      initialize(n);
      for(int i=0;i<m;i++){
         int u,v; cin >> u >> v;
         u--;v--;
         join(u,v);
      }
      set <int> count;
      for(int i=0;i<n;i++)count.insert(find(i));  
      printf("Case %d: %d\n",x++,count.size());    
   }
	return 0;
}
