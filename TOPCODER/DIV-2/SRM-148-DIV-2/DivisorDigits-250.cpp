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



class DivisorDigits{
	public: int howMany(int number){
		int num[15];
		for(int i=0;i<15;i++)num[i]=0;
		int aux = number;
		while(aux){
			int n = aux%10;
			if(number%n==0){
				num[n] ++;
			}
			aux /=10;
		}
		int c=0;
		for(int i=0; i<15; i++){
			if(num[i]>0)c+=num[i];
		}
		return c;
	}
};