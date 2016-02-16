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

bool isPal(char* s, int n){
    for (int i = n / 2; i > -1; --i)
        if (s[i] != s[n - i - 1])
            return false;
    return true;
}

bool isAl(char* s, int n){
    for(int i=1; i<n; i++){
        if(isPal(s , i)&& isPal(s + i,n - i))return true;       
    }
    return false;
}



int main(){
    int nCase, n;
    scanf("%d", &nCase);
    char* line = new char[200000];
    while (nCase--) {
        scanf("%s", line);
        n = strlen(line);
        if(isAl(line, n))printf("alindrome\n");
        else if (isPal(line,n))printf("palindrome\n");
        else printf("simple\n");
    }
	return 0;
}

