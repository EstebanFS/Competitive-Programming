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
#define MAX(a,b) ((a>b)?(a):(b))
#define MAXN 1001

int dp[MAXN][MAXN];
set <char> letters;
vector <string> words;
int maxSize;

int lcs(string s, string t){
    int m = s.size(), n= t.size();
    if(m==0 || n==0) return 0;
    for(int i=0;  i<=m; ++i)dp[i][0]=0;
    for(int j=1; j<=n; j++)dp[0][j]=0;
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; j++){
            if(s[i] == t[j])dp[i+1][j+1] = dp[i][j]+1;
            else dp[i+1][j+1] = MAX(dp[i+1][j], dp[i][j+1]);
        }
    }
    return dp[m][n]; 
}

int firstTest(int d){
    int nWords; cin >> nWords;
    string word; cin >> word;
    words.push_back(word);
    maxSize=word.size();
    for(int i=0; i<word.size(); i++)letters.insert(word[i]);
    int originalSize = letters.size(); 
    //D(originalSize);
    for(int i=1; i<nWords; i++){
        cin >> word;
        words.push_back(word);
        int auxSize=word.size();
        //D(auxSize);
        maxSize = max(maxSize, auxSize);
        set<char> auxLetters;
        for(int j=0; j<word.size(); j++)auxLetters.insert(word[j]);
        if(originalSize != auxLetters.size()){
            printf("Case #%d: Fegla Won\n",d);
            return 0;  
        }   
    }
    return 1;  
}

int main(){
    int cases; cin >> cases;
    for(int d=1; d<=cases; d++){
        letters.clear();
        words.clear();
        if(firstTest(d)==0)continue;
        printf("Case #%d: %d\n",d ,(maxSize - lcs(words[0], words[1])));
        //cout << maxSize - lcs(words[0], words[1]) << endl;
    }

	return 0;
}
