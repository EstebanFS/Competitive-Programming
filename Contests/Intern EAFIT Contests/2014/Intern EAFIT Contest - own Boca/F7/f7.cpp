# include <algorithm>
# include <iostream>
# include <iterator>
# include <sstream>
# include <fstream>
# include <cassert>
# include <cstdlib>
# include <string>
# include <cstring>
# include <cstdio>
# include <vector>
# include <cmath>
# include <queue>
# include <stack>
# include <map>
# include <set>
# define ll long long
# define MAXNEGATIVE -1000000005

using namespace std;

int main(){
	int n;
	while(cin>>n){
		vector <int> comp(n);
		for(int i=0;i<n;i++){
			cin>>comp[i];	
		}
		sort(comp.rbegin(), comp.rend());
		int max = 0;
		int ans=0;		
		for(int i=0;i<n;i++){
            int aux = comp[i] + n;
			if(aux >= max){
                max = std::max(max,comp[i]+(i+1));
                ans++;   
            }
		}
		cout << ans << endl;	
	}
	

return 0;
}
