// COCI
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

string keyboard[] = {"2", "22", "222", //a, b, c
                    "3", "33", "333", //d, e, f
                    "4", "44", "444", //g, h, i
                    "5", "55", "555", //j, k, l
                    "6", "66", "666", //m, n, o
                    "7", "77", "777", "7777", //p, q, r, s
                    "8", "88", "888", //t, u, v
                    "9", "99", "999", "9999"}; //w, x, y, z
int pressed[11];
string input, sol;

int
main() {
  for (int i = 1; i <= 9; ++i) {
    int x;
    cin >> x;
    pressed[x] = i;
  }
  cin >> input;
  int n = input.size();

  int last = -1;
  // Construimos la solución original, es decir, con el teclado bueno.
  for (int i = 0; i < n; ++i) {
    string pressing = keyboard[input[i] - 'a']; //Secuencia que vamos a presionar
    if (last == pressing[0] - '0') sol += "#";
    last = pressing[0] - '0';
    sol += pressing;
  }
  // Convertir la solución de acuerdo al teclado malo.
  for (int i = 0; i < sol.size(); ++i) {
    if (sol[i] == '#') printf("#");
    else printf("%c", '0' + pressed[sol[i] - '0']);
  }
  puts("");
  return 0;
}
