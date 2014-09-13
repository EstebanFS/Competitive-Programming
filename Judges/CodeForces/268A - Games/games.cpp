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

#define D(x) cout << #x " is " << x << endl;

int main(){
int n,ch,c,cv;
c=0;
cin>>n;
int vh[n];
int vv[n];
for(int i=0;i <n;i++){
    cin>>ch>>cv;
    vh[i]=ch;
    vv[i]=cv;
} 
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(vh[i]==vv[j]){
            c++;
        }
    }
} 
cout<<c;
return 0;
}