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

double h(double side) {
	return cos(1/(sin((side/2)/side))) * side;
}

int main() {
	double sum = 0;
	for(int i = 0; i < 6; ++i) {
		double side;
		cin >> side;
		sum += side;
	}
	double base = sum/3;
	cout << (h(base) * base)/(h(1)) << endl;
	return 0;
}

