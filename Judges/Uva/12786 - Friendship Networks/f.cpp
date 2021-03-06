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

int main(){
	int n;
	while(cin>>n){
		priority_queue<int> q;
		int grade;
		for(int i=0;i<n;i++){
			cin>>grade;
			q.push(grade);	
		}
		bool can=true;
		while(!q.empty()){
			grade = q.top(); q.pop();
			if(q.size()<grade){
				can=false;
				break;
			}
			vector <int> auxGrades;
			for(int i=0;i<grade; i++){
				int grades = q.top();q.pop();
				auxGrades.push_back(grades);
			}
			for(int i=0;i<grade;i++){
				int number=auxGrades[i];
				number--;
				if(number>0){
					q.push(number);	
				}
			}
		}
		if(can)cout << "1" << endl;
		else cout << "0" << endl;
	}

	return 0;
}


