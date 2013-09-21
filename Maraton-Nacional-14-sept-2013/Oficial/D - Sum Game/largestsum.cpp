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

int MAXN;

int main(){
    string line;
    while(getline(cin, line)) {
        MAXN = 0;
        stringstream ss(line);
        int num;
        int acum = 0;
        while (ss >> num) {
            acum += num;
            if (acum < 0) acum = 0;
            MAXN = max(MAXN, acum);
        }
        cout << MAXN << endl;  
    }
    return 0;
}
