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
#define msi map<string, int>
#define mis map<int,msi>

vector<msi> days;

int findTop(int n){
   msi rankingGeneral;
   mis ranking;
   for(int i=0;i<days.size();i++){
      msi aux=days[i];
      msi::const_iterator itr;
      for(itr = aux.begin(); itr != aux.end(); ++itr){
         string word=(*itr).first;
         int appear=(*itr).second;
         rankingGeneral[word]+=appear;
      } 
   }
   msi::const_iterator itr;
   for(itr = rankingGeneral.begin(); itr != rankingGeneral.end(); ++itr){
      string word=(*itr).first;
      int appear=(*itr).second;
      ranking[appear][word]++;
   } 
   mis::reverse_iterator itr3;
   for(itr3 = ranking.rbegin(); itr3 != ranking.rend(); ++itr3){
      msi actualAppear=(*itr3).second;
      int numberAppear=(*itr3).first;
      msi::const_iterator itr2;
      for(itr2 = actualAppear.begin(); itr2 != actualAppear.end(); ++itr2){
         cout<<(*itr2).first<<" "<<numberAppear<<endl;
         n--;
      }
      if(n<1)break;
   }
   return 0;   
}

int main(){
   string word;
   while(cin>>word){
      if(word=="<text>"){
         msi newMap;
         cin>>word;
         while(word!="</text>"){
            if(word.size()>=4)newMap[word]++;
            cin>>word;        
         } 
         days.push_back(newMap);
         if(days.size()>7)days.erase(days.begin()); 
      }
      if(word=="<top"){
         int number;
         string ignore;
         cin>>number>>ignore;
         printf("<top %d>\n",number);
         findTop(number);
         printf("</top>\n");
      }
   }
	return 0;
}
