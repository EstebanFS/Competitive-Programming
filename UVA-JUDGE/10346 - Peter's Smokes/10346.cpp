
#include <iostream> 

using namespace std;
 
int main(){
   int n, k;
   int  cantidad;
   while(cin>>n>>k){
     cantidad = n;
     while(k<=n){
     cantidad = cantidad + n/k;
     n = n/k + n%k;      
     }        
     cout << cantidad<<endl; 
    }    
 return 0;   
}
