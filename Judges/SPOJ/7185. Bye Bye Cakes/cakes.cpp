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

int lcm(int a, int b){return (a*b)/__gcd(a,b);}

int main(){
    int ans[4],h[4];
    while(cin >> ans[0]){
        if(ans[0]==-1)break;
        for(int i = 1; i < 4; ++i)cin >> ans[i];
        for(int i = 0; i < 4; ++i)cin >> h[i];
        for(int i = 0; i < 4; ++i){
            if(ans[i] <= 0)continue;
            int mul = lcm(ans[i],h[i])/h[i];
            for(int j=0; j < 4; ++j)ans[j]-=mul*h[j];
        }
        for(int i=0; i<3; i++)cout << abs(ans[i]) << " ";
        cout << abs(ans[3]) << endl;
    }
	return 0;
}


