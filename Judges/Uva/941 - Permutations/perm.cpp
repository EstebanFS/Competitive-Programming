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
#define ull unsigned long long

ull fact[21];

ull makeFact(){
   fact[0]=1;
   for(int i=1;i<21;i++)fact[i]=i*fact[i-1];
   return 0;
}

int main(){
   makeFact();
   int t; cin >> t;
   while(t--){
      string word; cin>>word;
      vector <char> letters;
      for(int i=0;i<word.size();i++)letters.push_back(word[i]);
      sort(letters.begin(),letters.end());
      ull iteration; cin >> iteration;
      string ans = "";
      int actualSize = word.size()-1;
      while(actualSize){
         ull letter = iteration/fact[actualSize];
         ans += letters[letter];
         iteration=iteration%fact[actualSize];
         actualSize--;
         letters.erase(letters.begin()+letter);
      }
      ans += letters[0];
      cout << ans << endl;      
   }
}
