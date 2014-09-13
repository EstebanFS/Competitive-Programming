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

int main(){
    string s; cin >> s;
    for(int i=0; i<s.size();i++){
        if(s[i]=='T')cout<< "U";
        else cout << s[i];   
    }
    cout << endl;
	return 0;
}
