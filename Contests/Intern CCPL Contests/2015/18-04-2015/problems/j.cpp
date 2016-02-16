#include <bits/stdc++.h>

using namespace std;
#define mic map<int, char>


int
main() {
  string line;
  getline(cin, line);
  mic map1;
  mic map2;
  for(int i = 0; i < line.size(); ++i)map1[i] = line[i];
  getline(cin, line);
  for(int i = 0; i < line.size(); ++i)map2[i] = line[i];
  int arr[5];
  arr[0] = 1; 
  arr[1] = 2;
  arr[2] = 4;
  arr[3] = 8;
  arr[4] = 16;
  while(getline(cin, line)){
    int state = 0;
    for(int i = 0; i < line.size(); ++i){
      int number = (line[i] - '0')*arr[4] + (line[i + 1] - '0')*arr[3] + (line[i + 2] - '0')*arr[2] + (line[i + 3] - '0')*arr[1] + (line[i + 4] - '0')*arr[0];
      if(number == 27) state = 0;
      else if(number == 31) state = 1;
      else if(!state) cout << map1[number];
      else cout << map2[number];
      i += 4;
    }
    cout << endl;
  }
  return 0;
}

