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
    int t; cin >> t;
    for(int x=0; x<t;x++){
        int n; cin >> n;
        int l=0,u=0;
        int actual; cin>>actual;
        for(int i=1; i<n; i++){
            int next; cin>>next;
            if(actual<next)u++;
            if(actual>next)l++;
            actual=next;        
        }
        printf("Case %d: %d %d\n",(x+1),u,l);   
    }
	return 0;
}
