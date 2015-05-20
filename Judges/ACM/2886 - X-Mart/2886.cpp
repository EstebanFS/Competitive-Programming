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
#define MAXN 20005
int n;
inline int index(int i){ if (i > 0) return i; else return n - i; }
inline int no(int i){ return -1*i; } //negation of a node

/*vector<int> g[MAXN];
int scc[MAXN];
//vector <int> g[MAXN];
vector <int> grev[MAXN];
vector <int> topo_sort;
//int scc[MAXN];
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
    for(int u=1; u<=n; u++){
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
}*/

vector<int> g[MAXN];
int d[MAXN], low[MAXN], scc[MAXN];
bool stacked[MAXN];
stack<int> s;
int ticks, current_scc;
void tarjan(int u){
  d[u] = low[u] = ticks++;
  s.push(u);
  stacked[u] = true;
  const vector<int> &out = g[u];
  for (int k=0, m=out.size(); k<m; ++k){
    const int &v = out[k];
    if (d[v] == -1){
      tarjan(v);
      low[u] = min(low[u], low[v]);
    }else if (stacked[v]){
      low[u] = min(low[u], low[v]);
    }
  }
  if (d[u] == low[u]){
    int v;
    do{
      v = s.top();
      s.pop();
      stacked[v] = false;
      scc[v] = current_scc;
    }while (u != v);
    current_scc++;
  }
}

void cleanTarjan(int si){
	for(int i = 0; i <= si; ++ i){
		stacked[i] = false;
		d[i] = -1;
	}
	ticks = 0;
	current_scc = 0;
	while(!s.empty())s.pop();
}

int main(){
	int c, p;
	while(cin >> c >> p && (c != 0 && p != 0)){
		n = p;
		//clean(n*2);
		cleanTarjan(n*2);
		for(int i = 0; i < c; ++i){
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			if(a == 0 && b != 0) g[index(no(b))].push_back(index(b));
			if(a != 0 && b == 0) g[index(no(a))].push_back(index(a));
			if(c == 0 && d != 0) g[index(d)].push_back(index(no(d)));
			if(c != 0 && d == 0) g[index(c)].push_back(index(no(c)));
			if(a != 0 && b != 0){
				g[index(no(a))].push_back(index(b));
				g[index(no(b))].push_back(index(a));	
			}
			if(c != 0 && d !=0){
				g[index(c)].push_back(index(no(d)));
				g[index(d)].push_back(index(no(c)));
			}
		}
		//find_scc(n*2);
		tarjan(1);
		bool can = true;
		for(int i = 1; i <= p; ++i){
			if(scc[i] == scc[index(no(i))]){
				can = false;
				break;
			}	
		}
		if(can) cout << "yes" << endl;
		else cout << "no" << endl;		
	}
	return 0;
}




