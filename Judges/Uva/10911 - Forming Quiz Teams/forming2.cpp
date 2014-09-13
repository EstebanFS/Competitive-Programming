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
#define MAX 20
#define pai pair<int, int>
vector <pair<int, int> > players;
const int INF = 1 << 30;

int readPlayers(int t){
    for(int i=0;i<(t*2);i++){
        string name; cin>>name;
        int x,y; cin >> x >> y;
        players.push_back(make_pair(x,y));    
    }
    return 0;    
}

double findDistance(int p1, int p2){
    pai dp1 = make_pair(players[p1].first, players[p1].second);
    pai dp2 = make_pair(players[p2].first, players[p2].second);
    double result1 = pow((double)(dp1.first - dp2.first),2.0);
    double result2 = pow((double)(dp1.second - dp2.second),2.0);
    return sqrt(result1 + result2);  
}

double mini(){
    double ans=0;
    int p1,p2;
    while(players.size()>2){
        double mini = findDistance(0,1);
        for(int i=0;i<players.size();i++)printf("%d,%d ",players[i].first,players[i].second);cout << endl;
        p1=0;p2=1;
        for(int i=2; i<players.size(); i++){
            double aux = findDistance(0,i);
            D("Entro");
            if(aux<mini){
                D(mini);D(aux);D(i);D(players[i].first);D(players[i].second);
                mini= aux;
                p2 = i;
            }                    
        }
        ans+=mini;
        D(ans);
        players.erase(players.begin()+p1);
        players.erase(players.begin()+p2);
    }
    ans+=findDistance(0,1);
    return ans;
}

int main(){
    int t;
    while(cin>>t){
        if(t==0)break;
        players.clear();
        readPlayers(t);
        sort(players.begin(), players.end()); 
        cout << mini() << endl;
    }
	return 0;
}
