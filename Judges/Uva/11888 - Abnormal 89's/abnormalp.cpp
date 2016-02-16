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
#define MAX 200000

bool isPalindrome(char* s, int n){
    for (int i = n / 2; i > -1; --i)
        if (s[i] != s[n - i - 1])
            return false;
    return true;
}

bool isAlindrome(char* s, int n){
    for(int i=1; i<n; i++){
        if(isPalindrome(s , i)&& isPalindrome(s + i,n - i))return true;       
    }
    return false;
}

int main(){
    int cases;
    scanf("%d",&cases);
    char* word = new char[200000];
    for(int i=0; i<cases;i++){
        scanf("%s", word);
        int n = strlen(word);
        if(isAlindrome(word, n))printf("alindrome\n");
        else if (isPalindrome(word,n))printf("palindrome\n");
        else printf("simple\n");       
    }
	return 0;
}
