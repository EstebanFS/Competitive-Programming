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

#define D(x) cout << #x " is " << x << endl
map<char, char> change;

int makeMap(){
    change['A']='T';
    change['T']='A';
    change['C']='G';
    change['G']='C';  
    return 0;  
}

int main(){
    string s; cin >> s;
    makeMap();
    for(int i=s.size()-1; i>=0; i--){
        cout << change[s[i]];    
    }
    cout << endl;
	return 0;
}
