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
int main(){
    int ab, ac, bd;
    while (cin >> ab>>ac>>bd){
        int num= ab*ac;
        int deno = bd - ac;
        int d = __gcd(num, deno);
        if(ac==0)deno=bd,d=1;
        cout << num/d << "/" << deno/d << endl;
             
    }  
return 0;
}
