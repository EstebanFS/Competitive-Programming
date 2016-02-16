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

#define MAXN 100000
#define INF 1000000
using namespace std;

vector <pair <int,int> > g[MAXN];
int d[MAXN];
int p[MAXN];

void dijkstra(int nod_ini, int  can_nod){
    for(int i=1; i<=can_nod; ++i){
     d[i] = INF;
     p[i] = -1;   
    } 
    
    d[nod_ini]=0;
    priority_queue< pair<int,int> > q;
    q.push(make_pair(nod_ini,0));
    while (!q.empty()){
     int node = q.top().first;
     int dist = q.top().second;   
     q.pop();
    
     if(dist>d[node]) continue;
        for(int i=0; i<g[node].size(); ++i){
             int hacia = g[node][i].first;
             int peso_m = g[node][i].second;   
                if(d[hacia] > dist + peso_m){
                    d[hacia] = dist + peso_m;
                    p[hacia] = node;
                    q.push(make_pair(hacia, d[hacia]));
                }
        }
    }    
}

void find_path (int t){
    vector <int> path;
    int cur = t;
    while(cur != -1){
    path.push_back(cur);
    cur = p[cur];
    }
    reverse(path.begin(), path.end());
    cout << path[0];
    for(int i = 1;i<path.size();i++){
        cout << " " << path[i];
    }
    cout <<";"<< " ";
}

void limpiar(){
    for(int i=0;i<MAXN;i++)g[i].clear(); 
}

int main(){
   int c;
   int x=1;
   while(cin>>c && c!=0){
        limpiar();
     for(int i=1; i<=c; i++){
         int num_casos;
         cin>>num_casos;
         for(int j=1;j<=num_casos; j++){
              int conx, pesoc;
              cin>>conx>>pesoc;
              g[i].push_back(make_pair(conx,pesoc));  
            }     
      }
      int nstart, nfinal;
      cin>>nstart>>nfinal;
      dijkstra( nstart , c);
      cout<< "Case " << x << ": Path = " ;
      find_path(nfinal);
      cout << d[nfinal] <<" second delay" <<endl;
    x++;
    } 
    
 return 0;   
}
