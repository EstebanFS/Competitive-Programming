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

#define ll long long
#define D(x) cout << #x << " " << x << endl;

int main() {
  int n;
  cin >> n;
  getchar();
  while(n--) {
    string line, command;
    getline(cin, line);
    stringstream ss;
    ss << line;
    vector <string> words;
    while(ss >> command) words.push_back(command);
    if(words.size() > 2 && (words[0] == "Simon" && words[1] == "says")) {
      cout << words[2];
      for(int i = 3; i < words.size(); ++i) cout << " " << words[i];
      cout << endl;
    }
  }
}
