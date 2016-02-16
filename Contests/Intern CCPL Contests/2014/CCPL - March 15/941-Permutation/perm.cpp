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
#define ull unsigned long long
#define MAX 21
ull fact[MAX];

ull factorial(){
    fact[0]=1;
    for(int i=1; i<=20; i++)fact[i] = i*fact[i-1];
}

string find(string word, int iterator){
           
    
}


int main(){
    factorial();
    int cases;
    cin >> cases;
    for(int i=0; i<cases; i++){
        string word;
        int iteration;
        cin >> word >> iteration;
        find(word, iteration);   
    }
    

	return 0;
}
