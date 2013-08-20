#include <algorithm>
#include <iostream>
#include <iterator>
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

using namespace std;

const int MAXN = 105;
const int INF = 150;
vector <pair <int, int> > g[MAXN];
int d[MAXN];

void limpiar(){
 for(int i=0; i< MAXN; i++){
 g[i].clear();
 }
}
void make_graph(int in, int to, int t){
 g[in].push_back(make_pair(to,t));
 g[to].push_back(make_pair(in,-t));      
}

bool bellman_ford(int s, int n){
    for(int u=0; u <= n ; ++u) d[u] = INF;
    d[s] = 0;
    
    for(int i = 1;  i <= n -1; ++i){
     for(int u = 0; u <= n; ++u){
            for(int k=0; k < g[u].size(); ++k){
                int v = g[u][k].first;
                int w = g[u][k].second;
                d[v] = min(d[v], d[u] + w);
            }
        }   
    } 
    
    for(int u = 0; u <= n; ++u){
        for(int k = 0; k < g[u].size(); ++k){
            int v = g[u][k].first;
            int w = g[u][k].second;    
            if(d[v]> d[u] + w){
                return true;    
            }
        }
    }
    
    return false;
    
}

int main(){
    int cn, n;
   while((cin>>cn>>n)&&(cn!=0)&&(n!=0)){
        limpiar();
        int a,b,c;
         cin>>a>>b>>c;
         int pri = a;
         make_graph(a, b, c);
      for(int i= 2; i<= n ; i++){
         cin>>a>>b>>c;   
         make_graph(a, b, c);   
        }
       if(bellman_ford(pri,cn)){  
      cout << "Y" <<endl;
       } else {
        cout << "N" <<endl;
    }
        
    }
    return 0;
}
