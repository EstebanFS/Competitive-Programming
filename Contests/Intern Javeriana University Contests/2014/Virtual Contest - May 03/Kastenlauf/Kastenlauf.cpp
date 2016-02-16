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
#define pai pair <int, int>

const int MAXN = 100005;
typedef pair <int, int> dist_node; // Datos del heap (dist, nodo)
typedef pair <int, int> edge; // Dato de las arista (nodo, peso)
vector <int> g[MAXN]; // g[u] = (v = nodo, w = peso)
int d[MAXN]; // d[u] La distancia mas corta de s a u
vector<pai> points;
int limit;
int nStores;


void bfs(int s, int n){ // s = fuente, n = numero de nodos
    for (int i = 0; i <= n; ++i) d[i] = -1;
    queue <int> q;
    q.push(s);
    d[s] = 0;
    while (q.size() > 0){
        int cur = q.front();
        q.pop();
            for (int i = 0; i < g[cur].size(); ++i){
            int next = g[cur][i];
            if (d[next] == -1){
                d[next] = d[cur] + 1;
                q.push(next);
            }
        }
    }
}
int findDistance(int p1, int p2){
    int x1 = points[p1].first;
    int y1 = points[p1].second;
    int x2 = points[p2].first;
    int y2 = points[p2].second;
    int ans = abs(x1-x2) + abs(y1-y2);
    return ans;  
}

int make_graph(){
    for(int i=points.size()-2; i>=0 ;i--){
        //cout << "Entra primer" << endl;
        int d = findDistance(limit, i);
        if(d>1000)continue;
        g[limit].push_back(i);
        g[i].push_back(limit);
    }
    for(int i=1;i<points.size()-1;i++){
        //cout << "Entra segundo" << endl;
        int d = findDistance(0,i);
        if(d>1000)continue;
        g[0].push_back(i);
        g[i].push_back(0);
    }
    for(int i=1; i<points.size()-1; i++){
        for(int j=i+1; j<points.size()-1; j++){          
            //cout << "Entra tercer" << endl;
            int d = findDistance(i,j);
            if(d>1000)continue;
            //D(d);D(i);D(j);
            g[i].push_back(j);
            g[j].push_back(i);    
        }   
    }
    return 0;    
}

int readPoints(){
    int x,y;cin >> x>>y;
    pai aux = make_pair(x,y);
    points.push_back(aux);
    for(int i=0; i<nStores; i++){
        cin >> x >> y;
        aux = make_pair(x,y);
        points.push_back(aux);
    }
    cin >> x >> y;
    aux = make_pair(x,y);
    points.push_back(aux);
    limit = points.size()-1;  
}

int printGraph(){
    for(int i=0; i<=limit; i++){
        for(int j=0; j<g[i].size();j++){
            cout << "Las conexiones de " << i << "va a: " << g[i][j] << endl;    
        }   
    } 
    return 0; 
}

string feeling(){
    if(d[limit]!=-1)return "happy";
    else return "sad";
}

int cleanGraph(){
    for(int i=0; i<=points.size(); i++)g[i].clear();
    points.clear();     
}

int main(){
    int cases; cin>>cases;
    for(int x=0; x<cases; x++){
        cin >> nStores;
        cleanGraph();
        readPoints();
        make_graph();
        //printGraph();
        bfs(0, points.size());
        cout << feeling()<< endl;
    }
	return 0;
}
