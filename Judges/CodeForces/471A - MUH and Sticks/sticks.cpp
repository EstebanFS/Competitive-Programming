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
    vector <int> sticks;
    for(int i = 0; i < 6; ++i){
        int x;
        cin >> x;
        sticks.push_back(x);
    }
    sort(sticks.begin(), sticks.end());
    if(sticks[0] == sticks[3]) cout << (sticks[4] == sticks[5] ? "Elephant" : "Bear");
    else if (sticks[1] == sticks[4]) cout << "Bear";
    else if (sticks[2] == sticks[5]) cout << (sticks[0] == sticks[1] ? "Elephant" : "Bear");
    else cout << "Alien";
	return 0;
}


