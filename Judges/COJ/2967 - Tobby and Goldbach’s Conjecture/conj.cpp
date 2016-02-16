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

using namespace std;

int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,

131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,

257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401};

int main(){
    int n; cin >> n;
    for(int i=0; i<n; i++){
        int number; cin >> number;
        int limit=0;
        for(int j=0; j<(sizeof(primes)/sizeof(*primes)); j++){
            if(primes[j]>number){
                limit=j-1;
                break;
            }
        }
        int ans=0;
        for(int k=0; k<=limit; k++)
            for(int l=k; l<=limit; l++)if(((primes[k]+primes[l])==number))ans++;
        cout << ans << endl;
    }

	return 0;
}
