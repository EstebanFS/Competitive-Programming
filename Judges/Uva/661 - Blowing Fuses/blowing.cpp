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
#define MAX 30

int amperesElectrodomestic[MAX];
bool stateElectrodomestic[MAX];


int main(){
    int n,m,c,cases=0;
    while(cin>>n>>m>>c){
        if(n==0 && m==0 && c==0)break;
        cases++;
        for(int i=0;i<n;i++){
            cin>>amperesElectrodomestic[i];   
        }
        for(int i=0;i<n;i++)stateElectrodomestic[i]=false;
        cout << "Sequence " << cases << endl;
        int ans =0,amperesMax=0;
        bool blow=false;
        for(int i=0;i<m;i++){
            int electrodomestic;
            cin >> electrodomestic;
            if(blow)continue;
            if(!stateElectrodomestic[electrodomestic-1]){
                ans+=amperesElectrodomestic[electrodomestic-1];
                stateElectrodomestic[electrodomestic-1] = true; 
                if(ans>c)blow = true;
                else amperesMax = max(ans, amperesMax); 
            }else{
                ans-=amperesElectrodomestic[electrodomestic-1];
                stateElectrodomestic[electrodomestic-1]=false;       
            }      
        }
        if(blow)cout<< "Fuse was blown." << endl<< endl;
        else{
            cout << "Fuse was not blown." << endl;
            cout << "Maximal power consumption was " << amperesMax << " amperes."
            << endl <<endl;   
        }   
    }

	return 0;
}
