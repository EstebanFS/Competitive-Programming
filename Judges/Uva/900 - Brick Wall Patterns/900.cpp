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

long long cladrillos(int l){
    long long p = 1;
    long long s = 1;
    for(int i =1 ; i<l; i++){
     long long temp = p + s;
     p = s;
     s = temp;      
    }
    
    return s;
}



int main(){
    int n;
    while((cin>>n)&&(n!=0)){
        cout << cladrillos(n)<<endl;        
    } 
   
 
 return 0;
}
