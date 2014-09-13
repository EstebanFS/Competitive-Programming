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
    int n;
    while(cin>>n){
        int numbers[n];
        for(int i=0;i<n;i++)cin>>numbers[i];
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(numbers[i]>numbers[j])ans++;  
            }    
        }
        printf("Minimum exchange operations : %d\n",ans);     
    }
	return 0;
}
