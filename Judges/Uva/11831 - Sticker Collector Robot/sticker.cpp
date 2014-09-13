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
#define Coord  pair <int, int>
#define MAXN 205

int place = 0;
Coord actualPos;
char arena[MAXN][MAXN];
int n,m,s,ans;

int find(char x){
    int auxx = actualPos.first;
    int auxy = actualPos.second;
    //D(arena[auxx][auxy]);
    if(x == 'N')return 0;   
    if(x == 'L')return 1;
    if(x == 'S')return 2;
    if(x == 'O')return 3;
    //arena[auxx][auxy] = '.';
    return 4;
}

int turn(int t){
    place += t;
    if(place >=4)return 0;
    if(place <0) return 3;
    //D(place);
    return place;  
}

int move(){
    Coord aux;
    if(place == 0) aux = make_pair(-1,0);
    if(place == 1) aux = make_pair(0,1);
    if(place == 2) aux = make_pair(1,0);
    if(place == 3) aux = make_pair(0,-1);
    int x = actualPos.first + aux.first;
    int y = actualPos.second + aux.second;
    //D(actualPos.first);
    //D(actualPos.second);
    //D(x);
    //D(y);
    if(x <0) return 0;
    if(x >n-1) return 0;
    if(y <0) return 0;
    if(y >m-1) return 0;
    if(arena[x][y] == '#')return 0;
    //D(arena[x][y]);
    if(arena[x][y] == '*'){
        //D("Entra en *");
        ans++;
        arena[x][y] = '.';
    }
    Coord newPos = make_pair(x,y);
    actualPos = newPos;
    //D(actualPos.first);
    //D(actualPos.second);
    return 1; 
}

int action(char a){
    if(a == 'D')place = turn(1);
    if(a == 'E')place = turn(-1);
    if(a == 'F')move();
    return 0;   
}

int main(){
    while(cin>>n>>m>>s){
        if(n==0 && m==0 && s==0)break;
        ans =0;
        //D(n);
        //D(m);
        //D(s);
        for(int i=0;i<n;i++){
            string line;
            cin>>line;
            for(int j=0;j<m;j++){
                arena[i][j] = line [j];
                int aux = find(arena[i][j]);
                if(aux<4){
                    place = aux; 
                    actualPos = make_pair(i,j);
                }
                //D(aux); 
            }  
            //cout << endl; 
        }
        string act;
        cin >> act;
        for(int i=0; i<s; i++){
            //D(act[i]);
            action(act[i]);    
        }
        cout << ans << endl;   
    }
	return 0;
}
