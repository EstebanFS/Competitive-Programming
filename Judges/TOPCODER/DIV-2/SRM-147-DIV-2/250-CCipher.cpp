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

char find(char x, int s){
	if((x - s) < 65 ){
		int aux = 65 - (x-s);
		return (char)((90-aux)+1);
	} 
	
	return (char)(x-s);
}

class CCipher{
	public: string decode(string cipherText, int shift){
		string ans= "";
		for(int i=0; i<cipherText.size(); i++){
			ans += find(cipherText[i], shift);
		}
		return ans;
	}
};