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
#define mci map <char, int>
#define pci pair <int, int>
mci position;
pci initial;
pci final;
set <pci> routes;
pci route;

int makeMap(){
    for(int i=65; i<=90; i++)position[i] = i-'A';
    return 0;     
}

int firstTest(){
    char li,lf; int ni,nf; cin >> li >> ni;
    initial = make_pair(position[li],ni);
    cin >> lf >> nf;
    final = make_pair(position[lf],nf);
    int modli,modlf,modni,modnf;
    modli= position[li]%2; modlf=position[lf]%2;
    modni= ni%2; modnf=nf%2;
    //D(modli);D(modni);D(modlf);D(modnf);D(position[li]);D(ni);D(position[lf]);D(nf);
    if(((modli==modlf)&&(modni==modnf))||((modli!=modlf)&&(modni!=modnf)));
    else{
        cout << "Impossible" << endl;
        return 1; 
    } 
    return 0;
}

int findRoutes(int n){
    pci auxPos;
    if(n==1)auxPos=initial;
    else auxPos=final;
    //routes.insert(final);
    int columns = auxPos.first;
    int rows = auxPos.second;
    //D(columns);D(rows);
    //rutas a la derecha - arriba
    rows++;
    columns++;
    while((columns)<=7 && (rows<=8)){
        route = make_pair(columns,rows);
        //D(route.first);D(route.second);
        int sizeBefore = routes.size();
        routes.insert(route);
        if(sizeBefore == routes.size())return 1;
        rows++;columns++;
    }
    columns = auxPos.first;
    rows = auxPos.second;
    //rutas a la izquierda - arriba
    rows++;
    columns--;
    while((columns)>=0 && (rows<=8)){
        route = make_pair(columns,rows);
        //D(route.first);D(route.second);
        int sizeBefore = routes.size();
        routes.insert(route);
        if(sizeBefore == routes.size())return 1;
        rows++;columns--;
    }
    columns = auxPos.first;
    rows = auxPos.second;
    //rutas a la derecha - abajo
    rows--;
    columns++;
    while((columns)<=7 && (rows>=1)){
        route = make_pair(columns,rows);
        //D(route.first);D(route.second);
        int sizeBefore = routes.size();
        routes.insert(route);
        if(sizeBefore == routes.size())return 1;
        rows--;columns++;
    }
    columns = auxPos.first;
    rows = auxPos.second;
    //rutas a la izquierda - abajo
    rows--;
    columns--;
    //D(rows);D(columns);
    while(columns>=0 && rows>=1){
        route = make_pair(columns,rows);
        //D(route.first);D(route.second);
        int sizeBefore = routes.size();
        routes.insert(route);
        if(sizeBefore == routes.size())return 1;
        rows--;columns--;
    }
    return 0;
}

int main(){
    int cases; cin >> cases;
    makeMap();
    for(int d=0; d<cases; d++){
        if(firstTest()==1)continue;
        char ans1 = (65+final.first);
        int d1=final.second;
        char ans2 = (65+initial.first);
        int d2 = initial.second;
        if(final==initial){
            printf("%d %c %d\n",0 ,ans2, d2);
            continue;
        }
        if(findRoutes(1)==1){
            printf("%d %c %d %c %d\n",1 ,ans2, d2, ans1, d1); 
            continue;
        }
        findRoutes(2);
        char ans3 = (65+route.first);
        int d3 = route.second;
        printf("%d %c %d %c %d %c %d\n",2 ,ans2, d2, ans3, d3, ans1, d1);
                     
    }
    //mci::iterator it;
    //for(it=position.begin(); it!=position.end(); ++it)cout << it->first << " => " << it->second << '\n';
	return 0;
}
