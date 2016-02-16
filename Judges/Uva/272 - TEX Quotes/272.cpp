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

int find(int cont){
    if(cont%2==0){
        cout << "``";
        return 0;       
    } 
    cout << "''";
    return 0;
}

int main(){
    string line;
    int c = 0;
    stringstream ss;
    while(getline(cin , line)){
        for(int i=0; i<line.size(); i++){
            if(line[i]=='\"'){
                find(c);
                c++;     
            }else{
                cout << line[i];   
            }    
        } 
        cout << endl;             
    }
return 0;
}
