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

int main(){
    int n;
    while(cin >> n){
        if(n==0)break;
        double numbers[n];
        for(int i=0; i<n; i++)cin >> numbers[i];
        sort(numbers, numbers +n);
        double ans;
        if(n%2==0)ans =(numbers[n/2] + numbers[(n/2)-1])/2;
        else ans =numbers[((n+1)/2)-1];
        printf("%.1f\n",ans);
    }
	return 0;
}
