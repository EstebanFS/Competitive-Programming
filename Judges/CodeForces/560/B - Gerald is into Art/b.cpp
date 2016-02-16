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
#define pii pair<int, int>
#define MAXN 3

int main() {
	pii arr[MAXN];
	for(int i = 0; i < MAXN; ++i){
		int ai, bi;
		cin >> ai >> bi;
		arr[i] = pii(ai, bi);
	}
	vector <pii> results;
	pii first = pii(arr[1].first + arr[2].first, max(arr[1].second, arr[2].second));
	pii second = pii(arr[1].first + arr[2].second, max(arr[1].second, arr[2].first));
	pii third = pii(max(arr[1].first, arr[2].second), arr[1].second + arr[2].first);
	pii fourth = pii(max(arr[1].first, arr[2].first), arr[1].second + arr[2].second);
	results.push_back(first);
	results.push_back(second);
	results.push_back(third);
	results.push_back(fourth);
	bool can = false;
	for(int i = 0; i < results.size(); ++i){
		if(results[i].first <= arr[0].first && results[i].second <= arr[0].second) {
			can = true;
		}
	}
		
	int temp = arr[0].first;
	arr[0].first = arr[0].second;
	arr[0].second = temp;
	for(int i = 0; i < results.size(); ++i){
		if(results[i].first <= arr[0].first && results[i].second <= arr[0].second) {
			can = true;
		}
	}
		
	if(can) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}

