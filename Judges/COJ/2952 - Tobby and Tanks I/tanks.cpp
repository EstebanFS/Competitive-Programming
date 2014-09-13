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
#define MAX 1005
#define ll long long
int tanks[MAX];

int binarySearch(int low, int high, ll key) {
  while (high - low + 1 > 1) {
     int mid = low + (high-low) / 2;
     if (tanks[mid] > key) high = mid;
     else low = mid + 1;
  }
  if (tanks[high] <= key) return high;
  else return high - 1;
}

int main(){
   int n,q;
   while(cin>>n>>q){
      cin>>tanks[0];
      tanks[0]=1;
      for(int i=1;i<n;i++){
         int volume;cin>>volume;
         tanks[i]=tanks[i-1]+volume;
      }
      for(int x=0;x<q;x++){
         if(x!=0)cout<<" ";
         ll query;cin>>query;
         cout<<(binarySearch(0,(n-1),query)+1);
      }
      cout<<endl;   
   }
	return 0;
}
