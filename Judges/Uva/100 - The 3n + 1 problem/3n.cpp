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
	int a, b;
	while (cin >> a >> b){
		printf ("%d %d ",a , b);
		int maxi = 0;
		if (b < a) swap (a, b);
		for (int i = a; i <= b; ++i){
			int n = i;
			int count = 1;
			while (n != 1){
				if (n % 2 == 1) n = n*3 + 1;
				else n= n/2;
				count ++;
			}
			maxi = max (maxi, count);	
		}
		printf ("%d\n",maxi);	
	}
	return 0;
}




