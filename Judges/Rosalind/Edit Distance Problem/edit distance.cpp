using namespace std;
#include <iostream>
#include<string>

#define MAX 5005

int dp[MAX][MAX];

int main(){
    string s,t;cin >> s >> t;
    for(int i=0;i<=s.size();i++)dp[i][0]=i;
    for(int i=0;i<=t.size();i++)dp[0][i]=i;
    
    for(int i=1; i<=s.size();i++){
            for(int j=1; j<=t.size(); j++){
                    if(s[i-1]==t[j-1])dp[i][j]=dp[i-1][j-1];
                    else dp[i][j]= min(min((1+dp[i-1][j-1]),1+dp[i-1][j]),1+dp[i][j-1]);     
            }     
    }
    
    /*for(int i=0; i<=s.size(); i++){
            for(int j=0; j<=t.size(); j++)cout << dp[i][j] << " ";
            cout << endl;
    }*/
    
    cout << dp[s.size()][t.size()] << endl;
}
