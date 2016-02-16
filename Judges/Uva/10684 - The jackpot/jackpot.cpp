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
#define MAXN 10005
#define ll long long

ll dp[MAXN];

int main(){
    int n;
    while(cin >> n){
        if(n == 0)break;
        ll maxsum = 0;
        dp[0]=0;
        for(int i=0; i<n; i++){
            int number;
            cin >> number;
            dp[i+1] = max(dp[i], maxsum+ number);
            maxsum += number;
            if(maxsum <0)maxsum=0; 
        }
        if(maxsum == 0)cout << "Losing streak." << endl; 
        else cout << "The maximum winning streak is " << dp[n] << "." << endl;
    }
	return 0;
}
