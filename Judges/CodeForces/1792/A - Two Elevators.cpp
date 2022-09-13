#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int a, b, c, t;
  cin >> t;
  while(t--) {
    cin >> a >> b >> c;
    int firstElevator = abs(a - 1);
    int secondElevator = abs(b - c) + abs(c - 1);
    if(firstElevator == secondElevator) cout << 3 << endl;
    else if(firstElevator < secondElevator) cout << 1 << endl;
    else cout << 2 << endl;
  }
  return 0;
}
