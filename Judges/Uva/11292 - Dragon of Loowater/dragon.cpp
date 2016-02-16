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
#define MAX 20005

int aHeads[MAX];
int aKnights[MAX];

int defend(int nh, int nk){
    if(nh>nk){
        cout << "Loowater is doomed!" << endl;
        return 0;   
    }
    sort(aHeads, aHeads + nh);
    sort(aKnights, aKnights + nk);
    bool possible = true;
    int i=0,j=0,ans=0,numberKills=0;
    while(possible){
        if(aHeads[i]<=aKnights[j]){
            i++;
            ans += aKnights[j];
            j++;
            numberKills++;
        } else {
            j++;    
        }
        if(i == nh)possible = false;
        if(j == nk)possible = false;   
    }
    if(numberKills == nh){
        cout << ans << endl;
        return 0;
    }
    cout << "Loowater is doomed!" << endl;
    return 0;    
}

int main(){
    int numberHeads, numberKnights;
    while(cin>>numberHeads>>numberKnights){
        if(numberHeads == 0 && numberKnights == 0)break;
        for(int i=0; i<numberHeads; i++){
            cin>>aHeads[i];   
        }
        for(int i=0;i<numberKnights; i++){
            cin>>aKnights[i];   
        }   
        defend(numberHeads,numberKnights);
    }

	return 0;
}
