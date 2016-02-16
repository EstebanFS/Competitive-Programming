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
map<int,int> results;

int solve(int n){
	if(results[n]!=0)return results[n];
	int i=2;
	int ans=0;
	while(i!=1){
		i+=i;
		if(i>n)i=(i-1)%n;
		ans++;	
	}
	results[n]=ans;
	return ans+1;
}

int main(){
	int n;
	while(cin >> n){
		cout << solve(n) << endl;
			
	}
	return 0;
}


