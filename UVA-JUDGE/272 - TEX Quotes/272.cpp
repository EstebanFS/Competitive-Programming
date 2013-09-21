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

int find(int cont){
    if(cont%2==0){
        cout << "``";
        return 0;       
    } 
    cout << "''";
    return 0;
}

int main(){
    string line;
    int c = 0;
    stringstream ss;
    while(getline(cin , line)){
        for(int i=0; i<line.size(); i++){
            if(line[i]=='\"'){
                find(c);
                c++;     
            }else{
                cout << line[i];   
            }    
        } 
        cout << endl;             
    }
    

return 0;
}
