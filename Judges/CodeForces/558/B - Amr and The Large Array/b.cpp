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
#define MAXN 1000005

int ocurr[MAXN];
int start[MAXN];
int end[MAXN];
int n;

int main() {
	cin >> n;
	for(int i = 0; i < MAXN; ++i) {
		ocurr[i] = 0;
		start[i] = -1;
		end[i] = -1;
	}
	int maxi = 0;
	for(int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		ocurr[num] ++;
		if(start[num] == -1) start[num] = i;
		end[num] = i;
		maxi = max(maxi, ocurr[num]);
	}
	int mini = MAXN;
	int number = 0;
	for(int i = 0; i < MAXN; ++i){
		if(ocurr[i] == maxi && (end[i] - start[i]) < mini){
			mini = (end[i] - start[i]);
			number = i;
		}
	}
	printf("%d %d\n", start[number] + 1, end[number] + 1);
	return 0;
}

