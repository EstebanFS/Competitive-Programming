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
#define pii pair<char, int>

int main(){
	int t;
	int x = 1;
	cin >> t;
	while(t--){
		string n;
		cin >> n;
		pii maxi = pii(n[0], 0);
		pii mini = pii(n[0], 0);
		for(int i = 1; i < n.size(); ++i){
			if(n[i] != '0' && n[i] > maxi.first){
				maxi.first = n[i];
				maxi.second = i;
			}
			if(n[i] != '0' && n[i] < mini.first){
				mini.first = n[i];
				mini.second = i;
			}			
		}
		string ansMax = n;
		string ansMin = n;
		char aux;
		aux = ansMax[0];
		ansMax[0] = maxi.first;
		ansMax[maxi.second] = aux;
		aux = ansMin[0];
		ansMin[0] = mini.first;
		ansMin[mini.second] = aux;
		printf("Case #%d: %s %s\n",x++, ansMin.c_str(), ansMax.c_str());
	}

	return 0;
}




