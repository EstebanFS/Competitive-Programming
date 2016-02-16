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
map <string, string> wordtoabs,abstoword;

string find(string y){
    stringstream ss;
    ss << y.size()-2;
    return y[0] + ss.str() + y[y.size()-1];   
}



string convertwordtoabs(string x){    
    if(wordtoabs[x] == ""){
        string aux = find(x);
        wordtoabs[x] = aux;
        if(abstoword[aux] == ""){
            abstoword[aux] = x;
            return x;     
        } else {
            if(abstoword[aux] == x) return x;
            else {
                abstoword[aux] = "amb4543";
                return x;    
            }   
        }
    }
    return x;
  
}

string convertabstoword(string x){
    if(abstoword[x] != "" && abstoword[x] != "amb4543")return abstoword[x];
    if(abstoword[x] != "" && abstoword[x] == "amb4543")return x;
    return x;
    
}

string cmayus(string x){
    string ans = "";
    for(int i=0; i<x.size() ; i++){
       ans += toupper(x[i]);
    }  
    return ans; 
}

int wordorabs(string word, string nword, char y){
    if(y=='1'){
        if((word.size() == 3 && isdigit(word[1])) || (word.size() == 4 && 
        isdigit(word[1]) && isdigit(word[2]))){
            string cword = convertabstoword(word);
            if(isupper(nword[0]) && isupper(nword[nword.size()-1])){
                string ans = cmayus(cword); 
                cout << ans << endl;   
            } else{
                cout << nword[0] << cword.substr(1,cword.size()-2); 
                cout<< nword[nword.size()-1] << endl;
            }
            
                
        } else {
        convertwordtoabs(word);    
        cout << nword << endl;   
        }         
        return 0;
    }    
        
    if((word.size() == 3 && isdigit(word[1])) || (word.size() == 4 && 
        isdigit(word[1]) && isdigit(word[2]))){
            string cword = convertabstoword(word);
            if(isupper(nword[0]) && isupper(nword[nword.size()-1])){
                string ans = cmayus(cword); 
                cout << ans << y;   
            } else{
                cout << nword[0] << cword.substr(1,cword.size()-2); 
                cout<< nword[nword.size()-1] << y;
            }
            
                
    } else {
        convertwordtoabs(word);    
        cout << nword << y;   
    }         

return 0;   
}     


int main(){
    string line;
    while (getline(cin, line)){
        string word, nword;
        for(int i=0; i<line.size(); i++){
            if(line[i] == '-'  || line[i] == ',' || line[i] == '.' 
                || line[i] == '\"' || line[i] == '(' || line[i] == ')' 
                || line[i] == ':'  || line[i] == ';'  || line[i] == '!' 
                || line[i] == '?'  || line[i] == ' '){
                
                if(word.size()>= 3){
                    wordorabs(word, nword, line[i]);
                }
                else cout << nword << line[i];
                nword = word = "";        
            } else {
                nword += line[i];   
                word += tolower(line[i]);
            }  
        } 
        
        if(word.size()>= 3){
            char y = '1';    
            wordorabs(word, nword, y);
        }
        else cout << nword << endl;
        nword = word = "";        

    }

  

return 0;
}
