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
#define ull unsigned long long
#define pii pair<ull, float>


int main(){
    ull nTest;
	float maxGrade, avg;
    cin >> nTest >> maxGrade >> avg;
    ull sum = 0;
    vector <pii> grades;
    for(int i = 0; i < nTest; ++i){
        float grade;
		ull essay;
        cin >> grade >> essay;
        grades.push_back(pii(essay, grade));
        sum += grade;   
    }
    double actualAvg = (double)sum/(double)nTest;
    if(actualAvg>= avg) {
        cout << 0 << endl;
        return 0;
    }
    sort(grades.begin(), grades.end());
    //for(int i = 0; i < grades.size(); ++i) cout << grades[i].first << endl;
    ull ans = 0;
    bool can = false;
    for(int i = 0; i < grades.size(); ++i){
        float currGrade = grades[i].second;
        ull currEssay = grades[i].first;
        while((actualAvg < avg) && (currGrade < maxGrade)){
            ans += currEssay;
            currGrade++;
            actualAvg += (double)1/(double)nTest;
            if(actualAvg >= avg){
            	can = true;	
            	break;
            }
        }
        if(can)break;
    }
    cout << ans << endl;
    return 0;
}
