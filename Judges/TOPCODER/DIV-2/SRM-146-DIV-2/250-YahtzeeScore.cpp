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

class YahtzeeScore{
	public: int maxPoints(vector <int> toss){
		map<int, int> sum;
		for(int i=0; i<toss.size() ; i++){
			int n= toss[i];
		    sum[n] += n;
		}
		
		map<int,int>::iterator it = sum.begin();
		int max=0;
		for(it=sum.begin(); it!=sum.end(); ++it){
			if(it->second > max) max=it->second;
		}

		return max;
	}
};