#include <iostream>
#include<math.h>
#include<cstdio>
using namespace std;
char m[105][105];
int main() {
    int n1,n2;
    int co=1;
    int times=0;
    while(cin>>n1>>n2){
        if(n1==0&&n2==0)break;
        if(times!=0)cout << endl;   
        times++;
        for(int i=1;i<=n1;i++)
            for(int j=1;j<=n2;j++)cin >> m[i][j];
        cout<<"Campo #"<<co<<":"<<endl;
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                int c=0;
                if(m[i][j]!='*'){
                    if(m[i-1][j]=='*')c++;
                    if(m[i+1][j]=='*')c++;  
                    if(m[i][j+1]=='*')c++;
                    if(m[i][j-1]=='*')c++;
                    if(m[i-1][j-1]=='*')c++;
                    if(m[i-1][j+1]=='*')c++;
                    if(m[i+1][j-1]=='*')c++;
                    if(m[i+1][j+1]=='*')c++;
                    cout<<c;

                } else cout<<'*';
            }
            cout<<endl;
        }
        co++;
    }
    return 0;
}

