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

#define D(x) cout << #x " is " << x << endl
char m[3][3];
bool getWinner(char c){
    if(m[0][0]==c&&m[0][1]==c&&m[0][2]==c )return true;
    if(m[0][0]==c&&m[1][1]==c&&m[2][2]==c )return true;
    if(m[2][0]==c&&m[1][1]==c&&m[0][2]==c )return true;
    if(m[1][0]==c&&m[1][1]==c&&m[1][2]==c )return true;
    if(m[2][0]==c&&m[2][1]==c&&m[2][2]==c )return true;
    if(m[0][0]==c&&m[1][0]==c&&m[2][0]==c )return true;
    if(m[0][1]==c&&m[1][1]==c&&m[2][1]==c )return true;
    if(m[0][2]==c&&m[1][2]==c&&m[2][2]==c )return true;
    return false;
}

int main(){
    int t; cin >> t;
    while(t--){
        getchar();
        int cx=0,co=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                m[i][j]=getchar();
                if(m[i][j]=='X')cx++;
                if(m[i][j]=='O')co++;   
            }   
            getchar(); 
        }
        bool xWin= getWinner('X');
        bool oWin= getWinner('O'); 
        if((xWin&&oWin)||(xWin&&(cx-co!=1))||(oWin&&(cx-co!=0))||((cx-co!=1)&&(cx-co!=0)))cout << "no" << endl;
        else cout << "yes" << endl;
    }
	return 0;
}
