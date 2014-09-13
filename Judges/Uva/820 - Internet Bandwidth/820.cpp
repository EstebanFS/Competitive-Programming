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

const int MAXN = 105;
vector <int> g [MAXN];
int c [MAXN][MAXN];
int f [MAXN][MAXN];

int prev [MAXN];  

int limpiar(){
 for(int i=0;i<MAXN;i++){
        for(int j=0; j<MAXN; j++){
         c[i][j] = 0;   
         f[i][j] = 0;        
        }
     g[i].clear();
    }
        
 return 0;   
}

void connect (int i, int j, int cap){
 g[i].push_back(j);
 g[j].push_back(i);
 c[i][j] +=cap;
 c[j][i] +=cap;      
}

int maxflow(int s, int t, int n){
    for(int i=0; i<=n; i++)
      for( int j=0; j<=n; j++)
          f[i][j] = 0;
          
      int flow = 0;
      while(true){
        for(int i=0; i<= n; i++) prev[i] = -1;
        queue <int> q;
        q.push(s);
        prev[s] = -2;
        
        while(q.size() >0){
            int u = q.front(); q.pop();
            if(u == t) break;
            for(int i = 0; i<g[u].size(); ++i){
                int v = g[u][i];
                if(prev[v] == -1 and c[u][v] - f[u][v] > 0){
                    q.push(v);
                    prev[v] = u;   
                    
                }  
            }      
        }
    
    if(prev[t] == -1) break;
    int extra = 1 << 30;
    int end = t;
    while(end != s){
        int start = prev[end];
        extra = min(extra, c[start][end] - f[start][end]);
        end = start;
     }
     end = t;
     while (end != s){
        int start = prev[end];
        f[start][end] += extra;
        f[end][start] = -f[start][end];
        end = start;
     }
     flow +=extra;
    }
   return flow;
}


int main(){
  int cn;
  int cont =1;
  while(cin>>cn){
     if(cn==0)break;
     limpiar();
     cout << "Network " << cont << endl;
     cont++;
     int start, to, cc;
     cin >> start >> to >> cc;
     for(int i=1;i<=cc; i++){
      int st,sto, w;
      cin >> st >> sto >> w;
      connect(st-1,sto-1,w);            
     }
     cout << "The bandwidth is " <<  maxflow(start-1,to-1,cn) << "." << endl;   
     cout << endl;
    } 
    
    
 return 0;   
}
