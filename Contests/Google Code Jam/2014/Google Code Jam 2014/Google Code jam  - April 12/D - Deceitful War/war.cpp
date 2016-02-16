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
    int cases; cin >> cases;
    for(int i=1; i<=cases; i++){
        int woods; cin >> woods;
        double noami[woods], ken[woods];
        for(int j=0; j<woods; j++)cin>>noami[j];
        for(int j=0; j<woods; j++)cin>>ken[j];
        int ans[woods][woods];
        for(int j=0; j<woods; j++){
            if(ken[0] < noami[j])ans[0][j] = 1;
            else ans[0][j] = 0;         
        }
        if(woods > 1){
            for(int j=1; j<woods; j++){
                for(int x=0; x<woods; x++){
                    int aux;
                    if(ken[j] < noami[x])aux = 1;
                    else aux = 0;
                    ans[j][x] = max(aux, ans[j-1][x]);
                }         
            }
        }
        int result1=0;
        for(int j=0;j<woods;j++)if(ans[woods-1][j]==1)result1++;
        //cout << result1 << " ";
        sort(noami, noami + woods);
        sort(ken, ken + woods);
        int kenScore =0;
        //for(int j=0;j<woods;j++)cout << ken[j] << " " ;
        int start = woods-1;
        for(int j=woods-1;j>=0;j--){
            for(int x=start; x>=0; x--){
                if(ken[j] > noami[x]){
                    kenScore++;
                    start = x-1;
                    x=-1;   
                }
            }    
        }
        int result2 = woods-kenScore;
        printf("Case #%d: %d %d\n", i, result1, result2);
    }
	return 0;
}
