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
#define MAX 9
int fact[MAX];

int makeFactorial(){
    fact[0]=1;
    for(int i=1;i<MAX;i++)fact[i]=i*fact[i-1];
    return 0;
}

int main(){
    int n; cin >> n;
    int numbers[n], ans=0;
    for(int i=1;i<=n;i++)numbers[i-1]=i;
    makeFactorial();
    cout << fact[n] << endl;
    do {
        for(int i=0;i<n;i++)cout << numbers[i] << " ";
        cout << endl;
    } while (next_permutation(numbers,numbers+n) );
	return 0;
}
