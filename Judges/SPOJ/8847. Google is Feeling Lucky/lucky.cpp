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
#define MAXN 105

vector <string> g[MAXN];

int main(){
    int cases;
    cin >> cases;
    int x =1;
    while(cases--){
        string page;
        int value;
        int maxValue=0;
        for(int i=0; i<MAXN; i++)g[i].clear();
        for(int i=0; i < 10; i++){
            cin >> page >> value;
            g[value].push_back(page);
            maxValue = max(maxValue,value);
        }
        printf("Case #%d:\n",x++);
        for(int i=0; i<g[maxValue].size(); i++) cout << g[maxValue][i] << endl;
    }
	return 0;
}


