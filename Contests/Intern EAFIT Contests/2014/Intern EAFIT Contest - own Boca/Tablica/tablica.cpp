# include <algorithm>
# include <iostream>
# include <iterator>
# include <sstream>
# include <fstream>
# include <cassert>
# include <cstdlib>
# include <string>
# include <cstring>
# include <cstdio>
# include <vector>
# include <cmath>
# include <queue>
# include <stack>
# include <map>
# include <set>
# define ll long long
# define MAXNEGATIVE -1000000005

using namespace std;
int table[2][2];

int find(){
	int max=table[0][0] + table[0][1], ans=0;
	int aux = table[0][0]+table[1][0];
	if(aux>max){
		max=aux;
		ans=1;
	}
	aux = table[1][0]+table[1][1];
	if(aux>max){
		max=aux;
		ans=2;
	}
	aux = table[1][1]+table[0][1];
	if(aux>max){
		max=aux;
		ans=3;
	}
	cout << ans << endl;
}

int main(){
    while(cin>>table[0][0]>>table[0][1]>>table[1][0]>>table[1][1]){
   		 find();                                                                                                                            
    }

return 0;
}
