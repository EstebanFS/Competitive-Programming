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

using namespace std;

typedef long long ll;
#define D(x) cout << #x << " " << x << endl


int main() {
    int n;
    cin >> n;
    while(n--) {
        string number;
        cin >> number;
        int sum = 0;
        for(int i = 0; i < number.size(); ++i) {
            if(number[i] == '_') continue;
            sum += number[i] - '0';
            sum %= 9;
        }
        if(sum == 0 || sum == 9) printf("0 or 9\n");
        else printf("%d\n", 9 - sum);
    }
    return 0;
}
