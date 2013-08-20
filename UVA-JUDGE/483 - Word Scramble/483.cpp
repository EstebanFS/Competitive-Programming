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

int revert(string x){
    for(int i=x.size()-1;i>=0;i--){
        cout<<x[i];    
    }
    
  return 0;  
}


int main(){
    string line;
    while (getline(cin, line)){
      stringstream ss(line);
      string word;
      ss>>word;
      revert(word);
        while(ss>>word){
            cout<<" ";
           revert(word);   
        } 
     cout<<endl;  
    }
return 0;
}
