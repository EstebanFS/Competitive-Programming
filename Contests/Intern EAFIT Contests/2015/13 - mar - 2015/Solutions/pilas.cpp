//Esteban Foronda Sierra

using namespace std;

#include <iostream>
#include <stack>

int main(){
  stack <int> s;
  int n; cin>>n;
  while (n--) {
    string word; cin>>word;
    if (word == "PUSH") {
      int number; cin>>number;
      s.push(number);  
    }
    if (word == "POP"){
      if (!s.empty()) s.pop();
    }
    if (word == "TOP") {
      if (!s.empty()) cout << s.top() << endl;
      else cout << "EMPTY" << endl;
    }
  }
	return 0;
}
