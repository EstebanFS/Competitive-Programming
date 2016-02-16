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

 class Time{
public: string whatTime(int seconds){
		int h= seconds/3600;
		seconds = seconds - (h*3600);
		int m= seconds/60;
		seconds = seconds -(m*60);
		string total;
		stringstream stream,stream1,stream2;
		stream  << h; 
		total=stream.str()+ ":";
		stream1 << m; 
		total=total+stream1.str()+ ":";
		stream2  << seconds; 
		total=total + stream2.str();
		return total;
		
			
	}
};