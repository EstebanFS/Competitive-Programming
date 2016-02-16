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
    vector <int> trees;
    for(int i = 0; i < n; ++i){
        int t; cin >> t;
        trees.push_back(t);   
    }
    sort(trees.rbegin(), trees.rend());
    int maxValue = -1;
    for(int i=0; i < trees.size(); ++i){
        int aux = trees[i] + 2 + i;
        maxValue = max(aux, maxValue);   
    }
    cout << maxValue << endl;
    return 0;
}
