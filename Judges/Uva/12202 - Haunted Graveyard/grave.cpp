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
#define MAXN 905
#define INF 1000000000
typedef pair<int, int> edge;
vector <edge> g[MAXN]; // g[u] = (v = nodo, w= peso)
int d[MAXN];
int graves[MAXN][MAXN];
int matrixToEdges[MAXN][MAXN];
int edgeOfCycle;

//0:Grass
//1:Stone

void clearGraves(int n, int m){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            graves[i][j]=0;   
        }
    }
    for(int i=0; i<=(n*m); i++)g[i].clear();
}

void makeGraph(int n, int m){
    int x=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            matrixToEdges[i][j] = x;
            if(graves[i][j]==1){
                x++;
                continue;
            }else{
                if((graves[i][j+1] == 0) && ((j+1)<m)){
                    g[x].push_back(make_pair(x+1,1));
                    g[x+1].push_back(make_pair(x,1));
                }
                if((graves[i+1][j] == 0) && ((i+1)<n)){
                    g[x].push_back(make_pair(x+m,1));     
                    g[x+m].push_back(make_pair(x,1)); 
                }
                x++;
            }
        }
    }
}

void showGraph(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<g[i].size(); j++){
            cout << "El Nodo: " << i << " tiene conexion con: " << g[i][j].first << " Con peso: " << g[i][j].second << endl;
        }
    }   
}

bool bellman_ford(int s, int n){
    for(int i=0; i<=n; i++)d[i]=INF;
    d[s] = 0;
    for(int i=1; i <=n-1; i++){
        for(int u=0; u < n; u++){
            if (d[u] == INF) continue;
            for(int k=0; k < g[u].size(); k++){
                int v = g[u][k].first;
                int w = g[u][k].second;
                d[v] = min(d[v], d[u] + w);
            }          
        }
    }
    for(int u = 0; u < n; u++){
        if (d[u] == INF) continue;
        for(int k=0; k < g[u].size(); ++k){
            int v = g[u][k].first;
            int w = g[u][k].second;
            edgeOfCycle = v;
            if(d[v] > d[u] + w) return true;
        }
    }
    return false;
}

int main(){
    int w,h;
    while(cin >> w >> h){
        if(w==0 && h==0)break;
        clearGraves(w,h);
        int numberEdges = (w*h)-1;
        int stone;
        cin >> stone;
        for(int i=0;i<stone; i++){
            int u,v;
            cin >> u >> v;
            graves[u][v]=1;   
        }
        makeGraph(w,h);
        int holes;
        cin >> holes;
        int x1, y1, x2, y2, t;
        for(int i=0; i<holes; i++){
            cin >> x1 >> y1 >> x2 >> y2 >> t; 
            int u = matrixToEdges[x1][y1];
            int v = matrixToEdges[x2][y2];
            g[u].clear();
            g[u].push_back(make_pair(v,t));  
        }
        g[numberEdges].clear();
        //showGraph(numberEdges+1);
        bool cycle = bellman_ford(0,numberEdges+1);
        if(cycle)cout << "Never" << endl;
        else if(d[numberEdges] != INF) cout << d[numberEdges] << endl;
        else cout << "Impossible" << endl; 
    }
	return 0;
}


