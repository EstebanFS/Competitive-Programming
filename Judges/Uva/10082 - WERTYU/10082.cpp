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
//map <string, string> kb;
char kb[] = {'`','1','2','3','4','5','6','7','8','9','0','-','='
    ,'Q','W','E','R','T','Y','U','I','O','P','[',']','\\','A','S','D','F'
                ,'G','H','J','K','L',';','\'','Z','X','C','V','B','N','M'
                ,',','.','/' };

int size=sizeof kb/sizeof(int);

char find(char x){
     for(int i=1;i<sizeof(kb);i++){
        if(x == kb[i])return kb[i-1];   
    }
   return x;
}

int convert(string x){
  for(int i=0;i<x.size();i++){
    cout<<find(x[i]);    
    } 
 return 0;   
}

int main(){
    string line;
    while (getline(cin, line)){
      for(int i=0;i<line.size();i++){
         cout<<find(line[i]);   
      }
      cout<<endl;  
    }
    

return 0;
}
