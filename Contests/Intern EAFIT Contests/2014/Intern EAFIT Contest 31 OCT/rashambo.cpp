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
#define msi map <string, int>
msi words;

void createRock(){
     words["Kamen"] = 1;
     words["Rock"] = 1; 
     words["Pierre"] = 1; 
     words["Stein"] = 1; 
     words["Ko"] = 1;
     words["Koe"] = 1; 
     words["Sasso"] = 1; 
     words["Roccia"] = 1; 
     words["Guu"] = 1;   
     words["Kamien"] = 1; 
     words["Piedra"] = 1;           
}

void createScissors(){
     words["Nuzky"] = 2;
     words["Scissors"] = 2; 
     words["Ciseaux"] = 2; 
     words["Schere"] = 2; 
     words["Ollo"] = 2;
     words["Olloo"] = 2; 
     words["Forbice"] = 2; 
     words["Choki"] = 2; 
     words["Nozyce"] = 2;   
     words["Tijera"] = 2;    
}

void createPaper(){
     words["Papir"] = 3;
     words["Paper"] = 3; 
     words["Feuille"] = 3; 
     words["Papier"] = 3; 
     words["Papir"] = 3;
     words["Carta"] = 3; 
     words["Rete"] = 3; 
     words["Paa"] = 3; 
     words["Papier"] = 3;   
     words["Papel"] = 3;           
}


int main(){
    string leng,name;
    createRock();
    createScissors();
    createPaper();
    int x=1;
    while(cin >> leng >> name){
      string player1,player2;
      int score1=0;
      int score2=0;
      player1=name;
      cin >> leng >> name;
      player2 = name;
      string play1,play2;
      while(cin >> play1){
        if(play1 == "-" || play1 == "."){
          printf("Game #%d:\n",x++);
          cout << player1 << ": " << score1 << " point" << endl;
          cout << player2 << ": " << score2 << " point" << endl;
          if(score1 == score2)cout << "TIED GAME" << endl;
          else if(score1 < score2) cout << "WINNER: " << player2 << endl;
          else cout << "WINNER: " << player1 << endl;
          if(play1 == "-") cout << endl;
          break; 
        } else {
          cin >> play2;
          int n1,n2;
          n1 = words[play1];
          n2 = words[play2];
          if(n1 == 1 && n2 == 2) score1++;
          else if(n1 == 2 && n2 == 1) score2++;
          else if(n1 == 1 && n2 == 3) score2++;
          else if(n1 == 3 && n2 == 1) score1++;
          else if(n1 == 2 && n2 == 3) score1++;
          else if(n1 == 3 && n2 == 2) score2++;
        } 
      }                                    
    }
    return 0;
}
