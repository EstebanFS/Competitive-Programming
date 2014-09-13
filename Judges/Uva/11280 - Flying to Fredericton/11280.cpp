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
const int INF = 20000000;
vector <pair <int, int> > g[MAXN];
int L[MAXN][MAXN];
map <string, int> m;

void limpiar(){
     for(int i=0; i< MAXN; i++){
        g[i].clear();
     }
}

void make_graph(int in, int to, int t){
     g[in].push_back(make_pair(to,t));    
}

bool bellman_ford(int s, int n){
    for (int u = 0; u <= n; ++u) L[0][u] = INF;
    L[0][s] = 0;
    for (int i = 1; i <= n - 1; ++i){
        for (int u = 0; u < n; ++u) L[i][u] = L[i-1][u];

        for (int u = 0; u < n; ++u){
            for (int k = 0; k < g[u].size(); ++k){
                int v = g[u][k].first;
                int w = g[u][k].second;
                L[i][v] = min(L[i][v], L[i-1][u] + w);
            }

        }
    }
for (int u = 0; u < n; ++u) L[n][u] = L[n-1][u];

for (int u = 0; u < n; ++u){
    for (int k = 0; k < g[u].size(); ++k){
        int v = g[u][k].first;
        int w = g[u][k].second;
        if (L[n][v] > L[n-1][u] + w) return true;
    }
}
return false;

}

int main(){
   int cases;
   cin>>cases;
   for(int i=1;i<=cases;i++){
     limpiar();
     int cn;
     cin>>cn;
     for(int j=0;j<cn;j++){
         string line;
         cin>>line;
         m[line] = j;  
     }
        int ccn;
        cin>>ccn;
     
        for(int j=1;j<=ccn;j++){
             string a,b;
             int c;
             cin>>a>>b>>c;
             make_graph(m[a], m[b],c);  
        }
            int q;
            cin>>q;
            cout<<"Scenario #"<<i<<endl;   
            bellman_ford(0,cn);
            for(int j=1;j<=q;j++){
                 int qcase;
                 cin>>qcase;
              if(qcase>=cn){
                 if(L[cn][cn-1]==INF){
                 cout<<"No satisfactory flights"<<endl;       
                 }else{
                 cout<< "Total cost of flight(s) is $" << L[cn][cn-1]<<endl;
                }
              }else{
                 if(L[qcase+1][cn-1]==INF){
                 cout<<"No satisfactory flights"<<endl;       
                 }else{
                 cout<< "Total cost of flight(s) is $"<<L[qcase+1][cn-1]<<endl;
                }
              }
              
              if((j==q)&&(i!=cases))cout<<endl;
                
                  
              }
            

   
   }
   
   
    
 return 0;   
}
