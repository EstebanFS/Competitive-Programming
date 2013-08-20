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
# define MAXN 1005

using namespace std;
int a[MAXN];


int find(int n, int m){
    int min=1010;
    for(int i=0;i<=(m-n);i++){
           if((a[i+(n-1)]-a[i])<min){
                min= a[i+(n-1)]-a[i];   
            } 
    }
    cout << min << endl;
 return min;
}

int main(){
    int n,m;
    while(cin>>n>>m){
        int f;
        for(int i=0; i<m; i++){
               cin>>f;
               a[i]=f;
        }
        sort(a,a+m);
        find(n,m);
    }

return 0;
}
