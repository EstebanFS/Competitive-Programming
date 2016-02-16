# include <algorithm>
# include <iostream>
# include <iterator>
# include <sstream>
# include <fstream>
# include <cassert>
# include <cstdlib>
# include <string>
# include <cstring>
# include <cstdio>
# include <vector>
# include <cmath>
# include <queue>
# include <stack>
# include <map>
# include <set>
# define ll long long

using namespace std;


int find(ll x, ll y){
    int ans = abs(x) + abs(y);
    pair <ll, ll>p1; 
    pair <ll, ll>p2;
    if(x<0)p1=make_pair(-ans,0);
    else p1=make_pair(ans,0);
    
    if(y<0)p2=make_pair(0,-ans);
    else p2=make_pair(0,ans);
    
    ll x1 = p1.first;
    ll y1 = p1.second;
    ll x2 = p2.first;
    ll y2 = p2.second;
    
    
    if(x1 < 0) cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    else cout << x2 << " " << y2 << " " << x1 << " " << y1 << endl;
    
    
 return 0;   
}

int main(){
    long long x,y;
    while(cin>>x>>y){
        find(x,y);   
    }

return 0;
}
