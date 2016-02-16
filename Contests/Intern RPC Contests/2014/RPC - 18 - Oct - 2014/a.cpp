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
    int n;
    cin >> n;
    int lastValue = 0;
    char lastType = 'a';
    bool shuffle = true;
    for(int i=0; i<n; ++i){
        int value;
        char type;
        cin >> value >> type;
        if(value == lastValue || type == lastType){
            shuffle = false;
            break;     
        }else{
            lastValue = value;
            lastType = type;    
        }    
    }
    if(shuffle)cout << "B" << endl;
    else cout << "M" << endl;
	return 0;
}


