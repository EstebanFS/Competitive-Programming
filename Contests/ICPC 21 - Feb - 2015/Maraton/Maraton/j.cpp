using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
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
{ stringstream s; s << x; return s.str();}

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r;}

#define D(x) cout << #x " = " << (x) << endl
#define MAXN 1000

bool
solve(string nums, set <int> exist, int maxi) {
	if (nums == "") {
		
	}
}

int main(){
	string line;
	while(cin >> line) {
		string realLine = "";
		if (line[0] != '0') realLine += line[0];
		for (int i = 1; i < line.size(); ++i) {
			if (line[i] == '0') {
				if (line[i - 1] != '0') realLine += line[i];
			}
			else realLine += line[i];
		}
		realLine;
		solve(realLine);
		set<string> exist;
		vector<string> print;
		for(int i = 0; i < line.size(); ++i){
			string number = "";
			for (int j = i; j < line.size(); ++j){
				number += line[j];
				if(j + 1 < line.size() && line[j+1] == '0') continue;
				if(exist.count(number) == 0) {
					exist.insert(number);
					print.push_back(number);
					i = j;
					break;
				}
			}	
		}
		cout << print[0];
		for(int i = 1; i < print.size(); ++i) cout << " " << print[i];
		cout << endl;	
	}
	return 0;	
}
