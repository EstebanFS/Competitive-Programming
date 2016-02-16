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
#define ll long long
vector<int> numbers;
ll ans;
int t;

ll solve(){
    ans=0;
    int c=0;
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i=0; i<t; i++){
        int n;scanf("%d",&n);
        pq.push(n);       
    }
    while(pq.size()>1){
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        pq.pop();
        c=(a+b);
        ans+=c;
        pq.push(c);
    }
    return ans;
}

int main(){
    while(scanf("%d",&t)){
        if(t==0)break;
        cout << solve() << endl;
    }
	return 0;
}

