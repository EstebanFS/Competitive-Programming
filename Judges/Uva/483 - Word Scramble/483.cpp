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

void reverse(string x){
	for(int i = x.size() - 1; i >= 0; --i) cout << x[i];
}

int main(){
	string line;
	while(getline(cin, line)){
		string word;
		for(int i = 0; i < line.size(); ++i){
			if(line[i] == ' '){
				reverse(word);
				word = "";
				cout << line[i];
			} else word += line[i];
		}
		reverse(word);
		cout << endl;
	}
	return 0;
}
