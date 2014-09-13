//Esteban Foronda Sierra
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

using namespace std;

#define D(x) cout << #x " is " << x << endl

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }


vector <char> numbers;
int size1, size2,zeroCount;
string resp1, resp2;

int addNumbers(){
    resp1 = ""; resp2="";
    resp1 += numbers[0];
    resp2 += numbers[1];
    size1--;size2--;
    int x =2;
    int zeroResp1, zeroResp2;
    if(zeroCount > 0){
        if(zeroCount % 2 ==0){
            zeroResp1 = zeroCount/2;
            zeroResp2 = zeroResp1; 
        }else{
            zeroResp1 = (zeroCount+1)/2;
            zeroResp2 = zeroResp1 - 1;   
        }
        size1 -= zeroResp1;
        size2 -= zeroResp2;
        for(int i=0; i< zeroResp1; i++){
            resp1 += '0';       
        }
        for(int i=0; i< zeroResp2;i++){
            resp2 += '0';
        }   
    }
    while(size1>0 || size2>0){    
        if(size1>size2){
            resp1 += numbers[x];
            size1--;
        }else {
            resp2 += numbers[x];
            size2--;  
        }
        x++;      
    }
    int aux1 = toInt(resp1);
    int aux2 = toInt(resp2);
    return aux1 + aux2;    
}

int main(){
    int n;
    while(cin >> n){
        if(n==0)break;
        zeroCount=0;
        numbers.clear();
        for(int i=0; i< n; i++){
            char actualNumber; cin >> actualNumber;    
            if(actualNumber == '0')zeroCount++;
            else numbers.push_back(actualNumber);
        }
        sort(numbers.begin(), numbers.end());
        if(n%2==0){
            size1= n/2;
            size2 = size1;
        }else{
            size1 = (n+1)/2;
            size2 = size1 -1;    
        }
        cout << addNumbers() << endl;    
    }
	return 0;
}
