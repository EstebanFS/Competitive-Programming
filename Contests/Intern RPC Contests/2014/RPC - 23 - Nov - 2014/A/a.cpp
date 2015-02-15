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
#define maxContest 50

int main(){
    int n;
    cin >> n;
    int contest[maxContest];
    memset(contest, 0, sizeof(contest));
    for(int i = 0; i < n; ++i){
        string task;
        cin >> task; 
        contest[task[0] - 'A']++;   
    }
    int ans = 0;
    for(int i = 0; i < maxContest; ++i)cout << contest[i] << endl;
    for(int i = 0; i < maxContest; ++i)if(contest[i] != 0) ans++;
    cout << ans << endl;
	return 0;
}


