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

char find(char x, int s){
	if((x - s) < 65 ){
		int aux = 65 - (x-s);
		return (char)((90-aux)+1);
	} 
	
	return (char)(x-s);
}

class CCipher{
	public: string decode(string cipherText, int shift){
		string ans= "";
		for(int i=0; i<cipherText.size(); i++){
			ans += find(cipherText[i], shift);
		}
		return ans;
	}
};