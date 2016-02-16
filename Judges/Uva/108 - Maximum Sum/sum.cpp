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
    int n;
    while(cin >> n){
        int original[n][n];
        int comp[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> original[i][j];
                if(i==0 && j==0)comp[i][j] = original[i][j];
                if(i==0 && j>0)comp[i][j] = original[i][j] + comp[i][j-1];
                if(i>0 && j==0)comp[i][j] = original[i][j] + comp[i-1][j];   
                if(i>0 && j>0)comp[i][j] = original[i][j] + comp[i-1][j] + comp[i][j-1] - comp[i-1][j-1];    
            }    
        }
        /*for(int i=0; i<n; i++){
            for(int j=0; j<n ; j++)cout << comp[i][j] << " "; 
            cout << endl;
        } */
        int ans = comp[0][0];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = i; k < n; k++) {
                    for(int l = j; l < n; l++) {
                        int cur = comp[k][l];
                        if(i > 0) cur -= comp[i - 1][l];
                        if(j > 0) cur -= comp[k][j - 1];
                        if(i > 0 && j > 0) cur += comp[i - 1][j - 1];
                        ans = max(ans, cur);
                    }
                }
            }
        }
        cout << ans << endl
    }
	return 0;
}
