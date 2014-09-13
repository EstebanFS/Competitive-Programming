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

float numerador;
float denominador;
int find(float num){
    for(int i=1; i<1005; i++){
        if(fmod(num*i,1) == 0){
            numerador = num*i;
            denominador = i;
            return 0;  
        }   
    }
    return 0;
}

int main(){
    float ab, ac, bd;
    while (cin >> ab>>ac>>bd){
        double x=(ac)/((bd-ac)/ab);
        find(x);
        cout << numerador << "/" << denominador << endl;     
    }  
return 0;
}
