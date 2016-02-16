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
#define MAX 1000005

using namespace std;


int main(){
    int n,p;
    while(cin >> n){
        if(n==0)break;
        cin >> p; n++;
        int ans[3];
        if(p%2==0){ans[0]=(n-p);ans[1]=(n-(p-1));ans[2]=(p-1);}
        else {ans[0]=(n-p);ans[1]=(n-(p+1));ans[2]=(p+1);}
        sort(ans, ans + 3);
        cout << ans[0];
        for(int i=1; i<3; i++){
            cout << " " << ans[i];   
        }
        cout << endl;
    }
	return 0;
}
