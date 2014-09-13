//Esteban Foronda Sierra
using namespace std;
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

#define MAXN 1000

vector<int> g[MAXN]; //Lista de adyacencia
int d[MAXN];  //Aristas usadas desde la fuente

void bfs(int s, int n){//s= fuente, n= numero de nodos
   //Marcar todos los nodos como no visitados
   for(int i=0; i < n; ++i)d[i] = -1;
   queue <int> q;
   q.push(s);
   d[s]=0;
   while(q.size() > 0){
      int cur = q.front(); q.pop();
      for(int i=0;i < g[cur].size(); ++i){
         int next = g[cur][i];
         if(d[next] == -1){
            d[next] = d[cur] +1;
            q.push(next);  
         }   
      }  
   }      
}


int main(){

	return 0;
}
