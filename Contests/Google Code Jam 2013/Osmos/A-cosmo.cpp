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


int absorb(int sta, int nab, int ncase){
	priority_queue < int, vector <int>,
	                greater<int> > q;               
	int nq = nab;
	for(int i=1; i<= nab; i++){
		int n;
		cin >> n;
		q.push(n);    
	}  
	if(sta == 1){
		cout << "Case #" << ncase << ": " << nab << endl;
		return 0;       
	}  
	int cs = 0;
	int aux = sta;
	while((cs <= nq) && (!q.empty())){
		int ns = q.top();
		if(aux <= ns){
			aux = aux + (aux-1);      
			cs++;     
		} else {  
			aux = aux + ns;      
			q.pop();     
		}    	    
	}
	if(cs > nq){
	    cout << "Case #" << ncase << ": " << nab << endl;
	} else {
	   cout << "Case #" << ncase << ": " << cs << endl; 
	}
 return 0;   
}

int main(){
    int cases;
    cin >> cases;
    for(int i=1; i<=cases; i++){
     int start, nabs;
     cin >> start >> nabs;
     absor(start,nabs, i);     
    }
    
    
   return 0; 
}
