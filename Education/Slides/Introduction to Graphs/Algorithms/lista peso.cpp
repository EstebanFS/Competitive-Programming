#include <vector>
#include <iostream>

using namespace std;

typedef pair <int, int> edge; // Llamar edge a un pair <int, int>
const int MAXN = 105;
vector <edge> g[MAXN];

int main(){
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
         // Agregar la arista de u a v con peso w
        g[u].push_back(edge(v, w));
    }
    for (int u = 0; u < n; ++u){
        for (int i = 0; i < g[u].size(); ++i){
            // Acceder al primer elemento de la arista
            int v = g[u][i].first;
            // Acceder al segundo elemento de la arista
            int w = g[u][i].second;
            printf("Edge from %d to %d with weight %d\n", u, v, w);
        }
    }
return 0;
}
