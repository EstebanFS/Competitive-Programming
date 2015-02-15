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
#define MAXN 105

vector <int> players;
int score=0;

bool equalScore(int n){
	for(int i=0; i<n-1; i++){
		if(players[i] != players[i+1])return false;
	}
	score = players[0];
	return true;
}


int main(){
	int n,t;
	while(cin >> n){
		if(n == 0)break;
		cin >> t;
		for(int i=0; i<n ; i++){
			players.push_back(0);	
		}
		int pos=0;
		bool first = true;
		bool equal = false;
		while(!equal){
			int sum = t/n;
			//D(sum);
			float auxSum = (float)t/(float)n;
			//D(auxSum);
			for(int i=0; i<n ; i++){
				players[i] += sum;	
				//D(players[i]);
				D(i);
			}
			int extraPlayers = (int)((auxSum - sum)*n);
			//D(extraPlayers);
			int aux = pos;
			for(int i=0; i<extraPlayers; i++){
				//D(aux);
				players[aux] +=1;
				//D(players[aux]);
				aux++;
				if(aux==n)aux=0;
			}
			//for(int i=0; i<players.size(); i++)D(players[i]);
			int deletePlayer = t%n;
			if(deletePlayer==0)deletePlayer=n;
			if(first){
				deletePlayer --;
				first=false;
			}
			//D(deletePlayer);
			pos = deletePlayer;
			//D(pos);
			players.erase (players.begin()+(deletePlayer));
			//for(int i=0; i<players.size(); i++)D(players[i]);
			n--;
			equal = equalScore(n);
		}
		cout << n << " " << score << endl; 		
	}

return 0;
}
