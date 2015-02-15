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
    vector <int> players;
    bool possible = false;
    for(int i = 0; i < n; ++i){
        int xi;
        cin >> xi;
        players.push_back(xi);    
    }
    sort(players.rbegin(), players.rend());
    vector <int> diff;
    for(int i=0; i<players.size(); i+=2){
        int result = players[i] - players[i+1];
        diff.push_back(result);
        if(result != 0) possible = true;  
    }
    if(possible){
        sort(diff.rbegin(), diff.rend());
        int acum = 0;
        vector <int> sum(diff.size());
        for(int i = sum.size()-1; i >= 0; --i){
            sum[i] = acum + diff[i];   
            acum = sum[i];
        }
        int points = 0, german = 1;
        for(int i=0; i<diff.size(); ++i){
            points += diff[i];
            if(i+1 == diff.size())continue;
            if(points > sum[i+1])break;
            else german++;   
        }
        cout << diff.size() - german << endl;
    }else cout << -1 << endl;
	return 0;
}


