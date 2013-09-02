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

class WidgetRepairs{
	public: int days(vector <int> arrivals, int numPerDay){
		int ndays = 0;
		int total = 0;
		for(int i=0; i<arrivals.size(); i++){
			total += arrivals[i];
			if(total <= numPerDay && total > 0){
				ndays++;
				total = 0;
			} else if(total > numPerDay){
				total -= numPerDay;
				ndays++;
			} 
		}
		while(total>numPerDay){
			total -= numPerDay;
			ndays++;
		}
		if(total>0) ndays++;
		return ndays;
	}
};