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
    int a,c,g,t;a=c=g=t=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='A')a++;   
        if(s[i]=='C')c++;
        if(s[i]=='G')g++;
        if(s[i]=='T')t++;
    }
    printf("%d %d %d %d\n",a,c,g,t);
	return 0;
}
