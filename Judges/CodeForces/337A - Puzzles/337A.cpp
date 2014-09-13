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
#define MAXN 1005
int a[MAXN];


int find(int n, int m){
    int min=1010;
    for(int i=0;i<=(m-n);i++){
           if((a[i+(n-1)]-a[i])<min){
                min= a[i+(n-1)]-a[i];   
            } 
    }
    cout << min << endl;
 return min;
}

int main(){
    int n,m;
    while(cin>>n>>m){
        int f;
        for(int i=0; i<m; i++){
               cin>>f;
               a[i]=f;
        }
        sort(a,a+m);
        find(n,m);
    }

return 0;
}
