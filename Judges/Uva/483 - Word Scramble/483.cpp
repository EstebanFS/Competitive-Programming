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

void reverse(string word){
	for (int i = word.size() - 1; i >= 0; --i)printf("%c", word[i]);
}

int main(){
	string line;
	while (getline (cin, line)){
		stringstream ss(line);
		string word;
		ss >> word;
		if (word.size() == 1)cout << word;
		else reverse (word);
		while (ss >> word){
			printf(" ");
			if (word.size() == 1)cout << word;
			else reverse (word);	
		}
		printf("\n");
	}
	return 0;
}




