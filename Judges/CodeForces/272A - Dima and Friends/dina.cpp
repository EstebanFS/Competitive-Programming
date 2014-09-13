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
	int n,st,con,na;
	cin>>n;
	con=0;
    for(int i=0;i<n;i++){
        cin>>na;
        st=st+na;
    }
    for(int i=1;i<=5;i++){
    	if(((st-1)+i)%(n+1)!=0)  {
    		con++;
    	}
    }
	cout<<con;
return 0;
}