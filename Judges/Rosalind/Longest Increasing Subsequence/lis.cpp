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
#define MAXN 1005
int d[MAXN], p[MAXN];
int a[MAXN];

int lis(int n){
    for (int i=0; i<n; ++i) {
    	d[i] = 1;
    	p[i] = -1;
    	for (int j=0; j<i; ++j)
    		if (a[i] >= a[j])
    			if (1 + d[j] > d[i]) {
    				d[i] = 1 + d[j];
    				p[i] = j;
    			}
    }
     
    int ans = d[0],  pos = 0;
    for (int i=0; i<n; ++i)
    	if (d[i] > ans) {
    		ans = d[i];
    		pos = i;
    	}
    cout << ans << endl;
    vector<int> path;
    while (pos != -1) {
    	path.push_back (pos);
    	pos = p[pos];
    }
    //reverse (path.begin(), path.end());
    for (int i=0; i<(int)path.size(); ++i)
    	cout << path[i] << ' ';
}


int main(){
    int n; cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
        D(a[i]);
    }
    for(int i=0; i<n; i++)cout << a[i];
    cout << endl;
    lis(n);
	return 0;
}
