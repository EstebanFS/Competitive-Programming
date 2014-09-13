using namespace std;
#include <iostream>
#include <vector>
const int MAXN = 15;

vector <int> g [MAXN];

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i){
        int u, v; 
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        if (u != v) g[v].push_back(u);
    }
return 0;
}
