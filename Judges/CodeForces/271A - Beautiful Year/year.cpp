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
int main() {
	int year,can,s,aux;
	can=0;
	cin>>year;
	s=0;
	year++;
	int v[3];
	while(s==0){
		aux=year;
		v[0]=aux%10;
		aux=aux/10;
		v[1]=aux%10;
		aux=aux/10;
		v[2]=aux%10;
		aux=aux/10;
		v[3]=aux%10;
		aux=aux/10;
		if(v[0]!=v[1]&&v[0]!=v[2]&&v[0]!=v[3]&&v[1]!=v[2]&&v[1]!=v[3]&&v[2]!=v[3]){
			s=1;
		} else {
			year++;
		}
	}
	cout<<year;
return 0;
}