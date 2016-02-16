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

#define D(x) cout << #x " is " << x << endl
#define mss map<string, string>
string roman[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
int decimal[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
mss romansNumber;

int makeRomans(){
  int size = 13;
  for(int i = 1; i < 4000; ++i){
    int number = i;
    string romanAux;
    for(int j = size - 1; j >= 0; --j){
      while(number >= decimal[j]){
          romanAux += roman[j];
          number -= decimal[j];
      }
    }
    string romanToNumber;
    ostringstream convert;   // stream used for the conversion
    convert << i;      // insert the textual representation of 'Number' in the characters in the stream
    romanToNumber = convert.str();
    romansNumber[romanAux] = romanToNumber;
    romansNumber[romanToNumber] = romanAux;
  }
  return 0;
}

int main(){
  makeRomans();
  string number;
  while(cin>>number) cout << romansNumber[number] << endl;
  return 0;
}
