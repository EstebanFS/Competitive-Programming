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
# define INF 100000
int dp[15];
int coin[] = {1,3,5};

int llenar(){
    for(int i=1; i<15; i++)dp[i] = INF;
    return 0;   
}

int main(){
    llenar();   
    dp[0]=0;
    int s = 11;
    for(int i = 1; i<=s; i++){
        for(int j=0; j<3; j++){
            if(coin[j]<=i && dp[i-coin[j]] +1 < dp[i]) dp[i] = dp[i-coin[j]]+1;   
        }   
    } 
    cout << dp[s];  
    //for(int i=0;i<s;i++)cout << dp[i];
       
    

return 0;
}
