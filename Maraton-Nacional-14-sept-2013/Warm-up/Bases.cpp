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

int b1, b2, b3, a, b;

float decimal(string num, int base) {
    float ans = 0;
    int expo = num.size()-1;
    int auxexpo = expo;
    for (int i = 0; i <= expo; i++) {
        ans += (num[i]-'0')*(pow((double)(base), (double)(auxexpo)));
        auxexpo--;
    }
    return ans;
}

int convert(int num, int base){
    string ans = "";
    while(num >0){
        stringstream aux;
        aux<< (num%base);
        //cout << "el aux es: " << aux.str() << endl;
        ans += aux.str();
        num = num/base;             
    }  
    string nans = string (ans.begin(), ans.end() );
    int tans = atoi(nans.c_str());
    //cout <<  << "Este es el valor" <<  endl;
    return tans;
}

int main() {
    while(cin >> b1 >> b2 >> b3 >> a >> b){
        stringstream as,bs;
        as<<a;
        bs<<b;
        float ans = decimal(as.str(), b1);
        ans += decimal(bs.str(), b2);
        //cout << ans << endl;
        int tans = convert((int)ans, b3);
        cout << tans << endl;
    }
}
