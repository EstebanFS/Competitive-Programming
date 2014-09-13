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

int revert(string x){
    for(int i=x.size()-1;i>=0;i--){
        cout<<x[i];    
    }
    
  return 0;  
}


int main(){
    string line;
    while (getline(cin, line)){
      stringstream ss(line);
      string word;
      ss>>word;
      revert(word);
        while(ss>>word){
            cout<<" ";
           revert(word);   
        } 
     cout<<endl;  
    }
return 0;
}
