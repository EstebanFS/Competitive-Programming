# include <algorithm>
# include <iostream>
# include <iterator>
# include <sstream>
# include <fstream>
# include <cassert>
# include <cstdlib>
# include <string>
# include <cstring>
# include <cstdio>
# include <vector>
# include <cmath>
# include <queue>
# include <stack>
# include <map>
# include <set>

using namespace std;

int a, b, n;

int main(){
    while (cin >> n >> a >> b) {
        if (a%2 == 1) a++;
        if (b%2 == 1) b++;
        int cont = 1;
        while (abs(a-b) > 1) {
            a /= 2;
            b /= 2;
            cont++;
            if (a%2 == 1) a++;
            if (b%2 == 1) b++;
        }
        cout << cont << endl;
    }
    return 0;
}
