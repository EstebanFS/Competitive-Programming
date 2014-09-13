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

/*
0: T T T F T T T
1: F F T F F T F
2: T F T T T F T
3: T F T T F T T
4: F T T T F T F
5: T T F T F T T
6: T T F T T T T
7: T F T F F T F
8: T T T T T T T
9: T T T T F T T
*/

char nums[10][7] = {{'-', '|', '|', ' ', '|', '|', '-'},
                 {' ', ' ', '|', ' ', ' ', '|', ' '},
                 {'-', ' ', '|', '-', '|', ' ', '-'},
                 {'-', ' ', '|', '-', ' ', '|', '-'},
                 {' ', '|', '|', '-', ' ', '|', ' '},
                 {'-', '|', ' ', '-', ' ', '|', '-'},
                 {'-', '|', ' ', '-', '|', '|', '-'},
                 {'-', ' ', '|', ' ', ' ', '|', ' '},
                 {'-', '|', '|', '-', '|', '|', '-'}, 
                 {'-', '|', '|', '-', ' ', '|', '-'}};

int
main() {
    int s;
    string n;
    while (cin >> s >> n && s) {
        string result;
        for (int i = 0; i < 7; i++) {
            result = "";
            if (i%3 == 0) {
                for (int j = 0; j < n.size(); j++) {
                    int num = n[j]-'0';
                    result += " ";
                    for (int k = 0; k < s; k++) {
                        result += nums[num][i];
                    }
                    if (j == n.size()-1)
                        result += " ";
                    else
                        result += "  ";
                }
                cout << result << endl;
            }
            else {
                for (int l = 0; l < s; l++) {
                    result = "";
                    for (int m = 0; m < n.size(); m++) {
                        int num2 = n[m]-'0';
                        result += nums[num2][i];
                        for (int k = 0; k < s; k++) {
                            result += " ";   
                        }
                        result += nums[num2][i+1];
                        if (m != n.size() - 1)
                            result += " ";
                    }
                    cout << result << endl;
                }
                i++;
            }
        }
        puts("");
    }
    return 0;
}
