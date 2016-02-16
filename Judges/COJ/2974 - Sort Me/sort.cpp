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
#define mcc map<char, char>
#define order map<string, int>

using namespace std;
mcc alpha;
mcc alphaNormalToReal;

string convertToNormal(string x){
	string response = x;
	for(int i=0; i<x.size(); i++){
		response[i] = alpha[x[i]];	
	}
	return response;
}

string convertToRare(string x){
	string response = x;
	for(int i=0; i<x.size(); i++){
		response[i] = alphaNormalToReal[x[i]];	
	}
	return response;
}

int main(){
	int words,x=1;
	while(cin >> words){
		if(words == 0) break;
		order ans;
		string alphabet; cin>> alphabet;
		for(int i=0;i<alphabet.size(); i++){
			alpha[alphabet[i]] = 'A'+i;
			alphaNormalToReal['A'+i] = alphabet[i];
		}
		for(int i=0; i<words; i++){
			string rareWord; cin>>rareWord;
			string auxWord = convertToNormal(rareWord);
			ans[auxWord] +=1;
				
		}
		cout << "year " << x << endl;
    	order::iterator pos;
    	for (pos = ans.begin(); pos != ans.end(); ++pos) {
			int numberWord = pos->second;
			string realWord = convertToRare(pos->first);
			for(int i=0;i<numberWord; i++){
				cout << realWord << endl;	
			}
    	}
		x++;
	}
		

return 0;
}
