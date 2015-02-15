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
#define MAXN 3005

int main(){
    int n;
    bool ans[MAXN];
    while(cin>>n){
        int value1, value2;
        for(int i=0; i<=n; ++i)ans[i]=false;
        cin >> value1;
        for(int i=1; i<n; ++i){
            cin >> value2;
            int result = abs(value1-value2);
            ans[result] = true;
            value1 = value2;
        }
        bool jolly = true;
        for(int i=1; i<n; ++i)if(!ans[i])jolly=false;
        if(jolly)cout << "Jolly" << endl;
        else cout << "Not jolly" << endl;
    }
	return 0;
}


