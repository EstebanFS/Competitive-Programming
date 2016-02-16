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
#define MAX 1000005

using namespace std;
int numberTask[MAX];

int binarySearch(int task,int n){
    int lowIndex = 0;
    int highIndex = n-1;
    int midIndex = (lowIndex + highIndex) / 2;
    while (lowIndex <= highIndex) {
        //printf("Low: %d y hi: %d\n", lowIndex, highIndex);
        if (numberTask[midIndex] == task) return midIndex;
        else if (numberTask[midIndex] < task) lowIndex = midIndex + 1;
        else highIndex = midIndex - 1;
        midIndex = (lowIndex + highIndex) / 2;
    }
    return -1;   
}

int main(){
    int n,k;
    while(cin >> n >> k){
        int task;
        for(int i=0; i<n; i++)scanf("%d",&numberTask[i]);
        sort(numberTask, numberTask + n);
        for(int i=0;i<k;i++){
            scanf("%d",&task);
            printf("%d\n",binarySearch(task,n));   
        }    
    }
	return 0;
}
