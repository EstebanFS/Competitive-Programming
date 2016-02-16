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
#define ll long long
#define MAXN 25
int gp, gc, gf, x = 1;
int arrayP[MAXN];
int arrayC[MAXN];
int arrayF[MAXN];

bool find_food(int current, ll p, ll c, ll f, int n){
	//printf("%d: receiving i:%d p:%d c:%d f:%d\n",x++, current, p, c, f);
	if((p == gp) && (c == gc) && (f == gf))return true;
	for(int i = current + 1; i < n; ++i){
		if(find_food(i, p + arrayP[i], c + arrayC[i], f + arrayF[i], n))return true;
	}
	return false;	
}

int main(){
	int t, n;
	cin >> t;
	while(t--){
		cin >> gp >> gc >> gf >> n;
		for(int i = 0; i < n; ++i)cin >> arrayP[i] >> arrayC[i] >> arrayF[i];
		bool can = false;
		for(int i = 0; i < n; ++i){
			if(find_food(i, arrayP[i], arrayC[i], arrayF[i], n)){
				can = true;
				break;
			}
		}
		if(can)printf("Case #%d: yes\n",x++);
		else printf("Case #%d: no\n",x++);
	}
	return 0;
}




