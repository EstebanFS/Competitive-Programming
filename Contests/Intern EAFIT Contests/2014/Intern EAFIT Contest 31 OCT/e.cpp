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


int main(){
    string key;
    while(cin >> key){
        if(key == "0") break;
        string text;
        cin >> text;
        if(key.size() <= text.size()){
            for(int i=0; i < text.size(); i+=key.size()){
                for(int j=0; j < key.size(); ++j){
                    if((i+j) < text.size()){
                        int w1 = (int)text[i+j];
                        int w2 = (int)(key[j]-'A'+1);
                        int result = (w1 + w2)%90;
                        char letter = (char)result;
                        cout << letter;      
                    }
                }
            }
            cout << endl;      
        }else{
            for(int i=0; i < key.size(); i+=text.size()){
                for(int j=0; j < text.size(); ++j){
                    if((i+j) < key.size()){
                        int w1 = (int)key[i+j];
                        int w2 = (int)(text[j]-'A'+1);
                        //D(w1);D(w2);
                        int result = ((w1 + w2)%90)+64;
                        //D(result);
                        char letter = (char)result;
                        cout << letter;      
                    }
                }
            }
            cout << endl;    
        }
    }
    return 0;
}
