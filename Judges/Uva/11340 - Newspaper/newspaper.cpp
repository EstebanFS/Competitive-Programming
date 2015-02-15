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
#define msi map<char, int>
#define ll long long
msi values;
string line;

ll amount(){
    ll result=0;
    for(int i=0; i<line.size(); i++)result += values[line[i]];
    return result;
}

int main(){
    int cases;
    cin >> cases;
    while(cases--){
        int letters;
        cin >> letters;
        values.clear();
        for(int i = 0; i < letters; ++i){
            char letter;
            int value;
            cin >> letter >> value;
            values[letter] = value;
        }
        int lines;
        cin >> lines;
        ll ans = 0;
        getchar();
        for(int i=0; i<lines; ++i){
            getline(cin,line);
            ans += amount();
        }
        printf("%.2f$\n", (double(ans)/100.00));
    }
	return 0;
}


