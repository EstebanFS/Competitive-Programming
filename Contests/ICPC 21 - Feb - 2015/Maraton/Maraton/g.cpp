using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
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


#define D(x) cout << #x " = " << (x) << endl
#define ll long long

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str();}

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r;}

template <class T> ll toll(const T &x)
{ stringstream s; s << x; ll r; s >> r; return r;}




int main(){
	string line;
	while(getline(cin, line)){
		stringstream ss(line);
		string first;
		ss >> first;
		string sballs = "";
		int x;
		for(x = 0; x < first.size(); ++x){
			if(first[x] != ':') sballs += first[x];
			else break;
		}
		x++;
		//D(sballs);
		ll balls = toll(sballs);
		//D(balls);
		bool arr[balls];
		string number = "";
		for(int j = x; j < first.size(); ++j)number += first[j];
		string had;
		for(int i = 0; i < balls; ++i) arr[i] = false;
		//D(number);
		if(number != "") arr[toll(number) - 1] = true;
		while(ss >> had)arr[toll(had) - 1] = true;
		int need = 0;
		//for(int i = 0; i < balls; ++i) cout << arr[i] << " ";
		//cout << endl;
		for (int i = 0; i < balls; ++i) if(!arr[i]) need++;
		if(need == 0) cout << "Goku already has them all!" << endl;
		else if(need == balls) cout << "Goku needs to find them all!" << endl;
		else {
			vector <int> print;
			for(int i = 0; i < balls; ++i) if(!arr[i]) print.push_back(i);
			cout << print[0] + 1;
			for(int i = 1; i < print.size(); ++i) cout << " " << print[i] + 1;
			cout << endl;
		}
	}
	return 0;
}
