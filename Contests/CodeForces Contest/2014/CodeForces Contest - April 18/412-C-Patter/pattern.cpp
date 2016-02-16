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
    while(cin >> n){
        string patterns[n];
        for(int i=0; i<n;i++)cin>>patterns[i];
        string ans = patterns[0];
        for(int i=0; i<patterns[0].size();i++){
            set<char> aux;
            for(int j=0; j<n; j++){
                char x = patterns[j][i];
                char lastChar;
                if(x != '?'){
                    int size = aux.size();
                    aux.insert(x);
                    lastChar = x;
                }
                if(aux.size()>1)ans[i]='?';
                if(aux.size()==1)ans[i]=lastChar;
                if(aux.size()==0)ans[i]='a';
            }       
        }
        cout << ans << endl; 
    }

	return 0;
}
