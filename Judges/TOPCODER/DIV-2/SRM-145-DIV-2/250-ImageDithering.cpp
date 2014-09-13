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

int find(char x, string y){
	for(int i=0; i<y.size(); i++){
		if(x==y[i])return 1;
	}
return 0;

}

class ImageDithering{
	public: int count(string dithered, vector<string> screen){
		int c=0;
		string line;
		while(!screen.empty()){
			line = screen.back();
     		screen.pop_back();
     		for(int i=0; i<line.size() ; i++){
     			c += find(line[i], dithered);
     		}
     	}
      return c;	
	}
};