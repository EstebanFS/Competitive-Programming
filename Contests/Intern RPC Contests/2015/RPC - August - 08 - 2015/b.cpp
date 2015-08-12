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
#define pii pair <int, int>
#define msi map <string, int>

int main() {
	int t;
	cin >> t;
	while(t--) {
			msi sounds;
			string line;
			getchar();
			getline(cin, line);
			stringstream  stm;
			msi m;
			stm << line;
			string record;
			int i = 0;
			vector <string> recorded;
			while(stm >> record) recorded.push_back(record);
			string animal, action, sound;
			while(cin >> animal && animal != "what") {
				cin >> action >> sound;
				m[sound]++;
			}
			cin >> animal >> animal >> animal >> animal;
			vector <string> foxWords;
			for(int i = 0; i < recorded.size(); ++i) {
				if(!m.count(recorded[i])) foxWords.push_back(recorded[i]);
			}
			cout << foxWords[0];
			for(int i = 1; i < foxWords.size(); ++i) cout << " " << foxWords[i];
			cout << endl; 
	}
	return 0;
}

