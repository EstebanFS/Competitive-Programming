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

int main(){
    int street, lanterns;
    cin >> lanterns >> street;
    vector <double> lant;
    for(int i = 0; i < lanterns; ++i){
        double pos;
        cin >> pos;
        lant.push_back(pos);
    }
    sort(lant.begin(), lant.end());
    double maxRadius = max(lant[0] - 0, street - lant[lant.size()-1]);
    for(int i = 0; i < lant.size() - 1; ++i) maxRadius = max(maxRadius, ((lant[i+1] - lant[i])/2));
    printf("%.10f",maxRadius);
	return 0;
}
