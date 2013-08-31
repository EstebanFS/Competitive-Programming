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

using namespace std;


class YahtzeeScore{
	public: int maxPoints(vector <int> toss){
		map<int, int> sum;
		for(int i=0; i<toss.size() ; i++){
			int n= toss[i];
		    sum[n] += n;
		}
		
		map<int,int>::iterator it = sum.begin();
		int max=0;
		for(it=sum.begin(); it!=sum.end(); ++it){
			if(it->second > max) max=it->second;
		}

		return max;
	}
};