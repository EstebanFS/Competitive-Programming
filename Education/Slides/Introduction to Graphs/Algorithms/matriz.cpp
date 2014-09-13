using namespace std;
#include <iostream>
const int MAXN = 15;
int M [MAXN][MAXN];


int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        u--; v--;
        M[u][v] = M[v][u] = 1;
    }
    return 0;
}
