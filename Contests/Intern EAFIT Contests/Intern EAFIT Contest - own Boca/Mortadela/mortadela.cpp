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

float convert(float x, float y){
	float ans = (x*1000)/y;
	return ans;	
}

int main(){
	float xo, yo;
	while(cin>>xo>>yo){
		int n;
		cin >> n;
		float min = convert(xo,yo);
		for(int i=0;i<n;i++){
			float xa, ya;
			cin>>xa>>ya;
			float aux = convert(xa,ya);
			if(aux<min)min=aux;	
		}
		//cout << min << endl;
		printf("%.2f\n",min);
	}

return 0;
}
