#include <algorithm>
#include <iostream>
#include <iterator>
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

using namespace std;

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
