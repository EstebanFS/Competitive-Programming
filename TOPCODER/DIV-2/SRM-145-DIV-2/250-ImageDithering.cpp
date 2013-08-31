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

int find(char x, string y){
	for(int i=0; i<y.size(); i++){
		if(x==y[i])return 1;
	}
return 0;

}

class ImageDithering{
	public: int count(string dithered, vector<string> screen){
		int c=0;
		string line;
		while(!screen.empty()){
			line = screen.back();
     		screen.pop_back();
     		for(int i=0; i<line.size() ; i++){
     			c += find(line[i], dithered);
     		}
     	}
      return c;	
	}
};