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

int main(){
    char letter; cin >> letter;
    vector <char> letters;
    while(letter>=65 && letter<=90){
        letters.push_back(letter);
        cin >> letter;
    }
    int comb = letter-'0';
    for(int i=0; i<letters.size();i++){
        for(int j=0;j<=(letters.size()-comb)+1; j++){
            cout << letters[i];
            for(int x=0;x<comb-1; x++)cout << letters[j+x];
            cout << endl;   
        } 
    }
	return 0;
}
