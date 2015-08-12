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
#define MAXN 200005
int hands[MAXN];
int shands[MAXN];
int diff1[MAXN * 2];
int diff2[MAXN];
int n;

bool kmp(int* needle, int* haystack, int m, int n){
	//int m = needle.size();
	vector<int> border(m);
	border[0] = 0;
	for (int i = 1; i < m; ++i) {
		border[i] = border[i - 1];
		while (border[i] > 0 and needle[i] != needle[border[i]])
		border[i] = border[border[i] - 1];
		if (needle[i] == needle[border[i]]) border[i]++;
	}
	//int n = haystack.size();
	int seen = 0;
	for (int i = 0; i < n; ++i){
		while (seen > 0 and haystack[i] != needle[seen])
		seen = border[seen - 1];
		if (haystack[i] == needle[seen]) seen++;
		if (seen == m) return true; // Ocurre entre [i - m + 1, i]
	}
	return false;
}

int main() {
	while(cin >> n) {
		for(int i = 0; i < n; ++i) scanf("%d", &hands[i]);
		sort(hands, hands + n);
		for(int i = 0; i < n - 1; ++i) {
			diff1[i] = hands[i + 1] - hands[i];
			diff1[i + n] = diff1[i];
		}
		diff1[n - 1] = hands[0] + (360000 - hands[n - 1]);
		diff1[n - 1 + n] = diff1[n - 1];
		for(int i = 0; i < n; ++i) scanf("%d", &shands[i]);
		sort(shands, shands + n);
		for(int i = 0; i < n - 1; ++i) diff2[i] = shands[i + 1] - shands[i];
		diff2[n - 1] = shands[0] + (360000 - shands[n - 1]);
		bool can = false;
		can = kmp(diff2, diff1, n, n * 2);
		if(can) printf("possible\n");
		else printf("impossible\n");
	}
	return 0;
}
