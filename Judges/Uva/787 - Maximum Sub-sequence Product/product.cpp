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
#define MAX -999999


int main(){
    int n;
    while(cin >> n){
        int result=n;
        int auxResult = n;
        while(cin >> n){
            if(n==MAX)break;
            auxResult *= n;
            if(auxResult == 0)auxResult =1;
            result = max(result, auxResult);  
        }
        cout << result << endl;            
    }

	return 0;
}
