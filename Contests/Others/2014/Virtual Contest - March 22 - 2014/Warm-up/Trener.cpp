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
    int players;
    while(cin>>players){
        string name;
        map <char, int> initial;
        for(int i=0; i<players; i++){
            cin>>name;
            initial[ name[0] ] += 1;
        }
        bool ans = false;
        for (std::map<char,int>::iterator it=initial.begin(); it!=initial.end(); ++it){
            //std::cout << it->first << " => " << it->second << '\n';
            if((it->second)>=5){
                cout<< it->first;
                ans = true;
            }
        }
        if(ans)cout << endl;
        else cout << "PREDAJA" << endl;
    }

	return 0;
}
