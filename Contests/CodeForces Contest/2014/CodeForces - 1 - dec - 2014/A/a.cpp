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
#define MAXN 200
int cubes[MAXN];
int sum[MAXN];

int buildP(){
    cubes[0] = 1;
    sum[0] = 1;
    for(int i = 1; i < MAXN; ++i){
        cubes[i] = cubes[i-1] + (i+1); 
        sum[i] = sum[i-1] + cubes[i];
    }
    //for(int i = 0; i < MAXN; ++i)cout << "Index: " << i << " value: " << sum[i] << endl;
    return 0;
}


int findElement(int e){
    for(int i = 0; i < MAXN; ++i){
        if(sum[i] == e) return i;
        if(e < sum[i]) return i-1;
    }
    return 0;
}

int main(){
    buildP();
    int nCube;
    cin >> nCube;
    cout << findElement(nCube) + 1 << endl;   
	return 0;
}


