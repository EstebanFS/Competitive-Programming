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
#define ll long long
#define MAXN 105
#define ll long long
#define pii pair <int, int>
#define piii pair<int, pii>

string labe[MAXN][MAXN];
ll d [MAXN][MAXN][MAXN];
int l, w, h, start[3], endPoint[3];

void bfs() {
  for(int i = 0; i < h; ++i) {
    for(int j = 0; j < l; ++j) {
      for(int k = 0; k < w; ++k) {
        d[i][j][k] = -1;
      }
    }
  }
  d[start[0]][start[1]][start[2]] = 0;
  queue<piii> q;
  q.push(piii(start[0], pii(start[1], start[2])));
  while(!q.empty()) {
    piii curr = q.front();
    q.pop();
    int currZ = curr.first, currY = curr.second.first, currX = curr.second.second;
    char currPos = labe[currZ][currY][currX];
    int currD = d[currZ][currY][currX];
    if(currPos == '-') {
      if((currZ + 1) < h && labe[currZ + 1][currY][currX] == '-') {
        if(d[currZ + 1][currY][currX] == -1) {
          d[currZ + 1][currY][currX] = currD + 1;
          q.push(piii(currZ + 1, pii(currY, currX)));
        }
      }
      if((currZ - 1) >= 0 && labe[currZ - 1][currY][currX] == '-') {
        if(d[currZ - 1][currY][currX] == -1) {
          d[currZ - 1][currY][currX] = currD + 1;
          q.push(piii(currZ - 1, pii(currY, currX)));
        }
      }
    }
    if((currY + 1) < l && labe[currZ][currY + 1][currX] != '#') {
      if(d[currZ][currY + 1][currX] == -1) {
        d[currZ][currY + 1][currX] = currD + 1;
        q.push(piii(currZ, pii(currY + 1, currX)));
      }
    }
    if((currY - 1) >= 0 && labe[currZ][currY - 1][currX] != '#') {
      if(d[currZ][currY - 1][currX] == -1) {
        d[currZ][currY - 1][currX] = currD + 1;
        q.push(piii(currZ, pii(currY - 1, currX)));
      }
    }
    if((currX + 1) < w && labe[currZ][currY][currX + 1] != '#') {
      if(d[currZ][currY][currX + 1] == -1) {
        d[currZ][currY][currX + 1] = currD + 1;
        q.push(piii(currZ, pii(currY, currX + 1)));
      }
    }
    if((currX - 1) >= 0 && labe[currZ][currY][currX - 1] != '#') {
      if(d[currZ][currY][currX - 1] == -1) {
        d[currZ][currY][currX - 1] = currD + 1;
        q.push(piii(currZ, pii(currY, currX - 1)));
      }
    }
  }
}

int main(){
  while(cin >> l >> w >> h && l != 0) {
    for(int z = 0; z < h; ++z) {
      for(int y = 0; y < l; ++y) {
        string line;
        cin >> line;
        labe[z][y] = line;
        for(int x = 0; x < line.size(); ++x) {
          if(line[x] == 'S') {
            start[0] = z;
            start[1] = y;
            start[2] = x;
          }
          if(line[x] == 'E') {
            endPoint[0] = z;
            endPoint[1] = y;
            endPoint[2] = x;
          }
        }
      }
    }
    bfs();
    cout << d[endPoint[0]][endPoint[1]][endPoint[2]] << endl;
  }
	return 0;
}
