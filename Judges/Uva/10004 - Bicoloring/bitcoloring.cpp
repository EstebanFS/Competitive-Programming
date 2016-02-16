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
#define MAXN 210


vector <int> g[MAXN];
int color[MAXN];

void cleanVector(int n){
    for(int i=0; i<n; i++){
        g[i].clear();
        color[i] = -1;
    }
}

bool bfs(int s, int n){
    queue <int> q;
    q.push(s);
    color[s]=0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0;i<g[cur].size();i++){
            int next = g[cur][i];
            if(color[next] == color[cur])return false;
            if(color[next] != -1);
            else {
                int auxColor = 0;
                if(color[cur]==1) auxColor = 0;
                else auxColor = 1;
                color[next] = auxColor;
                q.push(next);
            }
        }
    }
    return true;
}

int main(){
    int n,m;
    int from, to;
    while(cin>>n){
        if(n==0)break;
        cin >> m;
        cleanVector(n);
        for(int i=0; i<m;i++){
            cin >> from >> to;
            g[from].push_back(to);
            g[to].push_back(from);
        }
        bool ans = bfs(0,n);
        if(ans)cout << "BICOLORABLE." << endl;
        else cout << "NOT BICOLORABLE." << endl;
    }
	return 0;
}
