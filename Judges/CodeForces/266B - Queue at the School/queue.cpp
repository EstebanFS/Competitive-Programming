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

int main(){
	int n,t;
	string e,aux;
	cin >> n >> t >> e;
	aux=e;
	for(int i=1;i<=t;i++){
		for(int j=1;j<n;j++){
			if((e[j]=='G')&&(e[j-1]=='B')){
				aux[j]='B';
				aux[j-1]='G';
			}   
		}
	e=aux;
	}
	cout<<aux<<endl;
return 0;
}