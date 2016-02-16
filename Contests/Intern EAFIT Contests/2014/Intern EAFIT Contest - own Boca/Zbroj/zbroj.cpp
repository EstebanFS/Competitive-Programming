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

int transformMax(string x, string y){
    string auxNumber1 = x;
    string auxNumber2 = y;
    for(int i=0;i<x.size();i++){
            if(auxNumber1[i]=='5')auxNumber1[i]='6';  
            if(auxNumber2[i]=='5')auxNumber2[i]='6';      
    }
    int number1 =atoi(auxNumber1.c_str());
    int number2 =atoi(auxNumber2.c_str());  
    cout << number1 + number2 <<endl;
    return 0;
}

int transformMin(string x, string y){
    string auxNumber1 = x;
    string auxNumber2 = y;
    for(int i=0;i<x.size();i++){
            if(auxNumber1[i]=='6')auxNumber1[i]='5';  
            if(auxNumber2[i]=='6')auxNumber2[i]='5';      
    }
    int number1 =atoi(auxNumber1.c_str());
    int number2 =atoi(auxNumber2.c_str());  
    cout << number1 + number2 <<" ";
    return 0;
}


int main(){
    string number1, number2;
    while(cin >> number1 >> number2){
              transformMin(number1, number2);                    
              transformMax(number1, number2);
    }

return 0;
}
