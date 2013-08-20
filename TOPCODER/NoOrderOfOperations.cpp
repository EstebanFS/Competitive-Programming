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

using namespace std;

int main(){
    string x;
    while(cin>>x){
        int ans =0;
        ans = ans + (x[0]- '0');
        for(int i=1; i<x.length(); i++){
            if(x[i] == '-'){
                ans = ans - (x[i+1] - '0');
            }
            
            if(x[i] == '+'){
                ans = ans + (x[i+1] - '0');
            }   
                
            if(x[i] == '*'){
                ans = ans * (x[i+1] - '0');
            }
        }
        cout << ans << endl;   
        
    }


return 0;
}
