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
#define edge pair<int, int>
const int MAXN = 1115;
vector <int> posDoctor;
vector <edge> doctors;
vector <edge> branchs;
vector <edge> aux;
vector <int> g[MAXN];
int d[MAXN];
int node;
int n,m,k,di;

inline double euclideanDistance(int x1,int y1, int x2, int y2){
    //printf("La conexion es %d, %d con %d,%d\n",x1, y1, x2, y2);
    double result = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    //D(result);
    return result;
}

void readDoctors(int m){
    for(int i=0; i<m; ++i){
        int x,y;
        cin >> x >> y;
        doctors.push_back(edge(x,y));   
    } 
}

void readTree(int branch){
    for(int i=0; i<branch; ++i){
        int x,y;
        cin >> x >> y;
        aux.push_back(edge(x,y));
        if(i>0){
            g[node+i].push_back(node+(i-1));
            g[node+(i-1)].push_back(node+i);
        }
    } 
}

void makeCero(){
    for(int i=0; i<aux.size(); ++i){
        g[0].push_back(i+1);
        g[i+1].push_back(0);
        node++;      
    }
    for(int i=0; i<aux.size(); ++i)branchs.push_back(aux[i]);   
}

void makeConnection(){
    for(int i=0; i<aux.size(); ++i){
        int x1 = aux[i].first;
        int y1 = aux[i].second;
        for(int j=0; j<branchs.size(); ++j){
            int x2 = branchs[j].first;
            int y2 = branchs[j].second;
            double dist = euclideanDistance(x1,y1,x2,y2);
            if(dist <= k){
                g[j+1].push_back(node);
                g[node].push_back(j+1);
            }
        }
        branchs.push_back(aux[i]);
        node++;
    }  
}

void makeDoctorConnection(){
    for(int i=0; i<doctors.size(); ++i){
        int x1 = doctors[i].first;
        int y1 = doctors[i].second;
        for(int j=0; j<branchs.size(); ++j){
            int x2 = branchs[j].first;
            int y2 = branchs[j].second;
            double dist = euclideanDistance(x1,y1,x2,y2);
            if(dist <= di){
                g[j+1].push_back(node);
                g[node].push_back(j+1);
                posDoctor.push_back(node);
            }
        }
        branchs.push_back(doctors[i]);
        node++;
    }
}

void clean(int n){
    for(int i=0; i<=(n * 10) + m + 3; i++)g[i].clear();
    doctors.clear();
    aux.clear();
    branchs.clear();
    posDoctor.clear();
}

void bfs(int s, int n){
    for(int i=0; i<=node; ++i)d[i] = -1;
    queue <int> q;
    q.push(s);
    d[s]=0;
    while (q.size() > 0){
        int cur = q.front();
        q.pop();
        for(int i=0; i< g[cur].size(); ++i){
            int next = g[cur][i];
            if (d[next] == -1){
                d[next] = d[cur] +1;
                q.push(next);
            }
        }
    }
}

void showGraph(){
    for(int i=0; i<node; i++){
        for(int j=0; j<g[i].size(); ++j){
            printf("El nodo %d tiene conexion a %d\n", i, g[i][j]);   
        }
    }
}
int main(){
    int cases;
    cin >> cases;
    while(cases--){
        cin >> n >> m >> k >> di;
        clean(n);
        node=1;
        readDoctors(m);
        int branch;
        cin >> branch;
        readTree(branch);
        makeCero();
        for(int i=1; i<n; ++i){
            aux.clear();
            cin >> branch;
            readTree(branch);
            makeConnection();
        }
        makeDoctorConnection();
        //showGraph();
        bfs(0,node);
        bool result = false;
        for(int i=0; i<posDoctor.size(); ++i){
            int cur = posDoctor[i];
            if(d[cur] > 0){
                result = true;
                break;   
            }
        }
        //for(int i=0; i<node; ++i)printf("La distancia a %d es: %d\n",i,d[i]);
        if(result) cout << "Tree can be saved :)" <<endl;
        else cout << "Tree can't be saved :("<<endl;
    }
	return 0;
}


