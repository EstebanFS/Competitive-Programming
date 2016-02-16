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
#define MAXN 100005
vector <int> g[MAXN];
vector <int> grev[MAXN];
vector <int> topo_sort;
int scc[MAXN];
bool seen[MAXN];
int grades[MAXN];

void dfs1(int u){
    seen[u] = true;
    for(int i=0; i < g[u].size(); i++){
        int v = g[u][i];
        if(!seen[v])dfs1(v);
    }
    topo_sort.push_back(u);
}

void dfs2(int u, int comp){
    scc[u] = comp;
    for(int i = 0; i < grev[u].size(); i++){
        int v = grev[u][i];
        if(scc[v] == -1)dfs2(v,comp);
    }
}

int find_scc(int n){
    for(int u=0; u<n; u++){
        for(int i=0; i<g[u].size(); i++){
            int v = g[u][i];
            grev[v].push_back(u);   
        }
    }
    for(int i=0;i<n; i++){
        if(!seen[i])dfs1(i);   
    }
    reverse(topo_sort.begin(), topo_sort.end());
    int comp = 0;
    for(int i=0; i<n; i++){
        int u = topo_sort[i];
        if(scc[u] == -1)dfs2(u, comp++);   
    }
    return comp;
}

int clean(int n){
    for(int i=0; i<=n;i++){
        g[i].clear();
        seen[i]=false;
        scc[i]=-1;
        grev[i].clear();
        grades[i]=0;
    }
    topo_sort.clear();
    return 0;
}
int main(){
    int cases;
    cin >> cases;
    while(cases--){
        int n,m;
        cin >> n >> m;
        clean(n);
        for(int i=0;i<m;i++){
            int u,v;
            cin >> u >> v;
            u--;v--;
            g[u].push_back(v);
        }
        int comp = find_scc(n);
        for(int i=0; i<n; i++){
            for(int j=0;j<g[i].size();j++){
                int v = g[i][j];
                if(scc[i]!=scc[v])grades[scc[v]]++;
            }
        }
        int ans=0;
        for(int i=0; i<comp; i++)if(grades[i]==0)ans++;
        cout << ans << endl;
        
        
    }
	return 0;
}


