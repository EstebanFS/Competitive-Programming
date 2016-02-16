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
#define ll long long



int main(){
    int cases;
    cin>>cases;
    for(int i=0; i< cases ; i++){
        int objects;
        cin >> objects;
        map <string, int> categories;
        for(int j=0;j<objects;j++){
            string name, categorie;
            cin >> name >> categorie;
            categories[categorie] += 1; 
        }
        ll ans = 1;
        for (std::map<string,int>::iterator it=categories.begin(); it!=categories.end(); ++it){
            ans *= (it->second+1);
        }
        cout << ans -1 << endl;  
    }

	return 0;
}
