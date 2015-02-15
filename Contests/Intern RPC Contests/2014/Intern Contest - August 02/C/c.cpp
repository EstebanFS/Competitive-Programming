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
#define epoint pair<int, pair<int,int> >
#define edge pair<int,double>
#define dist_edge pair<double,int>
#define MAXN 205
#define INF 1<<30
vector<pair<int, pair<int,int> > > points;
int p[MAXN];
double d[MAXN];
vector <edge> g[MAXN];

double findEuclidean(int a,int b){
   double floora=points[a].first;
   double floorb=points[b].first;
   double xa=points[a].second.first;
   double xb=points[b].second.first; 
   double ya=points[a].second.second; 
   double yb=points[b].second.second;
   double distance = sqrt((pow(abs(floora-floorb)*5,2.0))+pow(abs(xa-xb),2.0) 
                     +pow(abs(ya-yb),2.0));
   return distance;   
   
}

void dijkstra(int s,int n){
   for(int i=0;i<=n;i++){
      d[i]=INF; p[i]=-1;   
   }
   priority_queue <dist_edge, vector<dist_edge>, greater<dist_edge> >q;
   d[s]=0.0;
   q.push(make_pair(0.0,s));
   while(!q.empty()){
      double dist=q.top().first;
      int cur = q.top().second;
      q.pop();
      if(dist>d[cur])continue;
      for(int i=0;i<g[cur].size();++i){
         int next=g[cur][i].first;
         double w_extra = g[cur][i].second;
         if(d[cur]+w_extra < d[next]){
            d[next]=d[cur]+w_extra;
            p[next]=cur;
            q.push(make_pair(d[next],next));   
         }   
      } 
   }    
}

int main(){
   int n,m;
   while(cin>>n>>m){
      for(int i=0;i<n;i++){
         int floor,x,y;
         cin>>floor>>x>>y;
         epoint point=make_pair(floor,make_pair(x,y));
         points.push_back(point);    
      }
      for(int i=0;i<m;i++){
         int u,v;
         string mode;
         cin>>u>>v>>mode;
         if((mode=="walking")||(mode=="stairs")){
            double d=findEuclidean(u,v);
            g[u].push_back(make_pair(v,d));
            g[v].push_back(make_pair(u,d));     
         }
         if(mode=="lift"){
            g[u].push_back(make_pair(v,1.0));
            g[v].push_back(make_pair(u,1.0));  
         }
         if(mode=="escalator"){
            double d=findEuclidean(u,v);
            g[u].push_back(make_pair(v,1.0));
            g[v].push_back(make_pair(u,d*3.0));            
         }   
      }
      int nq;
      cin>>nq;
      for(int i=0;i<nq;i++){
         int u,v;
         cin>>u>>v;
         dijkstra(u,n);
         int seq=v;
         vector <int> aseq;
         aseq.push_back(seq);
         while(p[seq]!=-1){
            aseq.push_back(p[seq]);
            seq=p[seq];  
         }
         cout<<aseq[(aseq.size()-1)];
         for(int i=aseq.size()-2;i>=0;i--)cout<<" "<<aseq[i];   
         cout<<endl;
      }
   }
	return 0;
}
