//Santiago Vanegas Gil.
#include <iostream>
#include <set>

using namespace std;

set <string> s;

int
main() {
  string line;
  while (getline(cin, line)) {
    if (s.count(line) == 0) {
      cout << line << endl;
      s.insert(line);
    }
  }
  return 0;
}
