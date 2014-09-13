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
int right(string x,int n){
    for(int i=0; i<(x.size()-n);i++)cout << "RIGHT" << endl;
    for(int i=x.size()-1; i>0; i--){
        printf("PRINT %c\n",x[i]);
        printf("LEFT\n");
    }
    printf("PRINT %c\n",x[0]);
    return 0;
}

int left(string x,int n){
    for(int i=0; i<n-1 ;i++)cout << "LEFT" << endl;
    for(int i=0; i<x.size()-1; i++){
        printf("PRINT %c\n",x[i]);
        printf("RIGHT\n");
    }
    printf("PRINT %c\n",x[x.size()-1]);
    return 0;
}

int main(){
    int n,k;
    while(cin>>n>>k){
     string slogan;cin >> slogan;
     if(k>(n/2))right(slogan,k);
     else left(slogan,k);   
    }
	return 0;
}
