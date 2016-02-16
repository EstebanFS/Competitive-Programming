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

int b1, b2, b3, a, b;

float decimal(string num, int base) {
    float ans = 0;
    int expo = num.size()-1;
    int auxexpo = expo;
    for (int i = 0; i <= expo; i++) {
        ans += (num[i]-'0')*(pow((double)(base), (double)(auxexpo)));
        auxexpo--;
    }
    return ans;
}

int convert(int num, int base){
    string ans = "";
    while(num >0){
        stringstream aux;
        aux<< (num%base);
        //cout << "el aux es: " << aux.str() << endl;
        ans += aux.str();
        num = num/base;             
    }  
    string nans = string (ans.begin(), ans.end() );
    int tans = atoi(nans.c_str());
    //cout <<  << "Este es el valor" <<  endl;
    return tans;
}

int main() {
    while(cin >> b1 >> b2 >> b3 >> a >> b){
        stringstream as,bs;
        as<<a;
        bs<<b;
        float ans = decimal(as.str(), b1);
        ans += decimal(bs.str(), b2);
        //cout << ans << endl;
        int tans = convert((int)ans, b3);
        cout << tans << endl;
    }
}
