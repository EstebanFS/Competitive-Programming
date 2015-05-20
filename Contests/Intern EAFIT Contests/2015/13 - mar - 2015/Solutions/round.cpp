//Santiago Vanegas Gil
#include <iostream>
 
using namespace std;
 
int
main() {
    int n, pos, pasan = 0, prom;
    cin >> n >> pos;
    int v[n];
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    prom = v[pos-1];
    for(int i = 0; i < n; i++) {
        if(v[i] >= prom && v[i] > 0) pasan++;
    }
    cout << pasan;
    return 0;
}
