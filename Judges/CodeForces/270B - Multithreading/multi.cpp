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
int main() {
	int n,cn,c;
	c=0;
	cin>>n;
	int v[n];
	for(int i=0;i<n;i++){
		cin>>cn;
		v[i]=cn;
	}
	for(int i=(n-1);i>0;i--){
		if(v[i]<v[i-1]){
			c= (i); 
			i=(-1);
		}
	}
	cout<<c;
	return 0;
}