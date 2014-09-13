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
	int n,cc,cb,cba;
	cin>>n;
	int c=0;
	cc=cb=cba=0;
	for(int i=0;i<n;i++){
		int ce;
		cin>>ce;
		if(c==0){
			cc=cc+ce;
		}
		if(c==1){
			cb=cb+ce;
		}
		if(c==2){
			cba=cba+ce;
		}
		c++;
		if(c==3){
			c=0;
		}
	}
	if((max(cc,max(cb,cba)))==cc){
		cout<<"chest";
	}
	if((max(cc,max(cb,cba)))==cb){
		cout<<"biceps";
	}
	if((max(cc,max(cb,cba)))==cba){
		cout<<"back";
	}
return 0;
}