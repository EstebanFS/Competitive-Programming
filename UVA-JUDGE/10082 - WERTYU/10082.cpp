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
//map <string, string> kb;
char kb[] = {'`','1','2','3','4','5','6','7','8','9','0','-','='
    ,'Q','W','E','R','T','Y','U','I','O','P','[',']','\\','A','S','D','F'
                ,'G','H','J','K','L',';','\'','Z','X','C','V','B','N','M'
                ,',','.','/' };

int size=sizeof kb/sizeof(int);

char find(char x){
     for(int i=1;i<sizeof(kb);i++){
        if(x == kb[i])return kb[i-1];   
    }
   return x;
}

int convert(string x){
  for(int i=0;i<x.size();i++){
    cout<<find(x[i]);    
    } 
 return 0;   
}

int main(){
    string line;
    while (getline(cin, line)){
      for(int i=0;i<line.size();i++){
         cout<<find(line[i]);   
      }
      cout<<endl;  
    }
    

return 0;
}
