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

int main(){
	string line;
	set<int> exist;
	vector<int> print;
	while(cin >> line) {
		string realLine = "";
		if (line[0] != '0') realLine += line[0];
		for (int i = 1; i < line.size(); ++i) {
			if (line[i] == '0') {
				if (line[i - 1] != '0') realLine += line[i];
			}
			else realLine += line[i];
		}
		//cout << line << endl;
		//cout << realLine << endl;
		line = realLine;
		exist.clear();
		print.clear();
		int i = 0; 
		while (i < line.size()) {
			string number = "";
			int num = 0;
			while (i < line.size() && (num == 0 || exist.count(num))) {
				number += toStr(line[i]);
				num = toInt(number);
				i++;
			}
			//printf("Sale num: %d i = %d\n", num, i);
			exist.insert(num);
			print.push_back(num);
		}
		cout << print[0];
		for(int i = 1; i < print.size(); ++i) cout << " " << print[i];
		cout << endl;	
	}
	return 0;	
}
