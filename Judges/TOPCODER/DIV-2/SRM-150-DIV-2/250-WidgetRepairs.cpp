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

class WidgetRepairs{
	public: int days(vector <int> arrivals, int numPerDay){
		int ndays = 0;
		int total = 0;
		for(int i=0; i<arrivals.size(); i++){
			total += arrivals[i];
			if(total <= numPerDay && total > 0){
				ndays++;
				total = 0;
			} else if(total > numPerDay){
				total -= numPerDay;
				ndays++;
			} 
		}
		while(total>numPerDay){
			total -= numPerDay;
			ndays++;
		}
		if(total>0) ndays++;
		return ndays;
	}
};