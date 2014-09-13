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

class FormatAmt{
	public: string amount(int dollars, int cents){
		string ans = "";
		stringstream stream,stream2;
		stream << dollars;
		stream2 << cents;
		string cent = "";
		string aux = stream.str();
		if(cents < 10) cent += "0" + stream2.str();
		else cent += stream2.str();
		if(aux.size()>=3){
			ans += aux.substr(aux.size()-3,aux.size());
			aux.erase(aux.size()-3,aux.size());
		}else{
			return "$" + aux + "." + cent;	
		}
		while(aux.size()>=3){
			ans = aux.substr(aux.size()-3,aux.size())+ "," + ans;
			aux.erase(aux.size()-3,aux.size());
		}
		if(aux.size()>0)ans = "$" + aux + "," + ans;
		else ans = "$" + ans;
		ans += "." + cent;
		return ans;
	}
};