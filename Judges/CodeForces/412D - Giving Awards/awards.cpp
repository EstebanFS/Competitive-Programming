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
#define MAXN 30005

int realtion;

vector <int> g[MAXN]; // La lista de adyacencia
bool seen[MAXN]; // El arreglo de visitados para el dfs
vector <int> topo_sort; // El vector del ordemamiento
void dfs(int u){
    seen[u] = true;
    for (int i = 0; i < g[u].size(); ++i){
        int v = g[u][i];
        cout<< v << endl;
        if (!seen[v]) dfs(v);   
    }
    topo_sort.push_back(u); // Agregar el nodo al ordenamiento
}
    
void topological(int n){ // n = numero de nodos
    topo_sort.clear();
    for (int i = 0; i < n; ++i) seen[i] = false;
    for (int i = 0; i < n; ++i) if (!seen[i]) dfs(i);
    //reverse(topo_sort.begin(), topo_sort.end());
}

void cleanVector(int n){
    for(int i=0; i<n; i++)g[i].clear();
}

int main(){
    int n,k,from,to;
    while(cin>>n>>k){
        realtion =0;
        cleanVector(n);
        for(int i=0;i<k;i++){
            cin >> from >> to;
            from--;to--;
            g[to].push_back(from);
            //g[from].push_back(to);
               
        }
        //dfs(0);
        topological(n);
        //for(int i=0; i<topo_sort.size();i++)cout << topo_sort[i]+1 << " "; 
    }

	return 0;
}
