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
    int m[6][6];
    int n;
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            m[i][j]=1;
        }
    }
    for(int i=2;i<5;i++){
        for(int j=2;j<5;j++){
            cin>>n;
            if(n%2==1){
                if(m[i][j]==0){
                    m[i][j]=1;
                }else{
                    m[i][j]=0;
                }           
                if(m[i+1][j]==0){
                    m[i+1][j]=1;
                }else{
                    m[i+1][j]=0;
                }   
                if(m[i-1][j]==0){
                    m[i-1][j]=1;
                }else{
                    m[i-1][j]=0;
                }   
                if(m[i][j+1]==0){
                    m[i][j+1]=1;
                }else{
                    m[i][j+1]=0;
                }   
                if(m[i][j-1]==0){
                    m[i][j-1]=1;
                }else{
                    m[i][j-1]=0;
                }   
            }
        }
    }
    for(int i=2;i<5;i++){
        for(int j=2;j<5;j++){
            cout<<m[i][j];
        }
            cout<<endl;
    }
return 0;
}