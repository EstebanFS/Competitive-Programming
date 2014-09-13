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

int main (){
  int max = 0;
  int nes = 0;
  int baj=0;
  int sub=0;
  int acu=0;
  int x;
  cin >> x;
  nes =x;
  for(int i=1;i<=nes;i++){
    int b;
    int s;
    cin>> b >> s;
    sub=s;
    baj=b;
    acu=acu+sub - baj;
    if(acu>max){
      max = acu;     
    }          
  }
  cout<<max;
  return 0;   
}