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

#define msi map<string, int>

int main(){
  int t;
  cin >> t;
  getchar();
  getchar();
  while(t --) {
    string tree;
    msi inventory;
    int forest = 0;
    while(getline(cin, tree) && tree != "") {
      inventory[tree]++;
      forest++;
    }
    msi :: iterator it;
    for(it = inventory.begin(); it != inventory.end(); ++it) {
      printf("%s %.4f\n", (it -> first).c_str(),
                          (((it -> second) * 1.0) / (forest * 1.0)) * 100.0);
    }
    if(t != 0) printf("\n");
  }
	return 0;
}
