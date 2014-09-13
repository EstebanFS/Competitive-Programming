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
#define MAX 10005

int d[MAX];
bool forbidden[MAX];

int number(int a[]){
   int ans = 0;
   ans += a[0]*1000;
   ans += a[1]*100;
   ans += a[2]*10;
   ans += a[3];
   return ans;  
}

int bfs(int s, int final){
   memset (d, -1, sizeof (d));
   queue <int> q;
   d[s]=0;
   q.push(s);
   //bool resultFound = false;
   while(!q.empty()) {
      int cur = q.front();
      q.pop();
      if(forbidden[cur]==true)continue;
      //visited[cur]=true;
      /*if(cur==final){
         resultFound = true;
         break;
      }*/
      int aux[4];
      /*aux[3]=cur%10;
      aux[2]=(cur%100)/10;
      aux[1]=(cur%1000)/100;
      aux[0]=cur/1000;*/
      //D(cur);
      //D(aux[0]);D(aux[1]);D(aux[2]);D(aux[3]); 
      for(int i=0;i<4;i++) {
         aux[3]=cur%10;
         aux[2]=(cur%100)/10;
         aux[1]=(cur%1000)/100;
         aux[0]=cur/1000;
         aux[i]+=1;
         aux[i]%=10;
         int num=number(aux);
         //if(visited[num]==false)q.push(num);
         if (forbidden[num]) continue;
         if (d[num] == -1) {
            d[num]=d[cur]+1;
            q.push(num);
         }
         /*aux[3]=cur%10;
         aux[2]=(cur%100)/10;
         aux[1]=(cur%1000)/100;
         aux[0]=cur/1000;*/
      }
      for (int i=0;i<4;i++) {
         aux[3]=cur%10;
         aux[2]=(cur%100)/10;
         aux[1]=(cur%1000)/100;
         aux[0]=cur/1000;
         aux[i]-=1;
         if(aux[i]==-1)aux[i]=9;
         int num = number(aux);
         if (forbidden[num]) continue;
         //if(visited[num]==false)q.push(num);
         if (d[num] == -1)  {
            q.push(num);
            d[num]=d[cur]+1;
         }
         /*aux [3] = cur % 10;
         aux [2] = (cur % 100) / 10;
         aux [1] = (cur % 1000) / 100;
         aux [0] = cur / 1000;*/
      }
   }
   //if(resultFound)return d[final];
   //else -1;
   return d[final];
}

int main(){
   int cases;cin>>cases;
   while(cases--){
      int s=0;
      memset(forbidden, 0, sizeof forbidden);
      for(double i=3;i>=0;i--){
         int n;scanf("%d",&n);
         s+=n*(int)round(pow(10.0, i));
      }
      int final=0;
      for(double i=3;i>=0;i--){
         int n;scanf("%d",&n);
         final+=n*(int)round(pow(10.0, i));
      }
      int f;scanf("%d",&f);
      for(int i=0;i<f;i++){
         int aux=0;
         for(double i=3;i>=0;i--){
            int n;scanf("%d",&n);
            aux+=n*(int)round(pow(10.0, i));
         }
         forbidden[aux]=true;   
      }
      if(forbidden[s]||forbidden[final]) cout << "-1" << endl;
      else if(s==final){
         printf("0\n");
         continue;   
      }
      else cout << bfs(s,final) << endl;
   }
	return 0;
}
