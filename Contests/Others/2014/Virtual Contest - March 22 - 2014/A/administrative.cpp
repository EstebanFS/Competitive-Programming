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
#define prices map < char, int >

int cStringToInt(string x){
    return atoi( x.c_str() );
}

int main(){
    int cases;
    cin >> cases;
    for(int i=0; i<cases; i++){
        int autom, event,number=1;
        cin >> autom >> event;
        map < int, prices > detailCar;
        map < string, prices > detailSpy;
        map < string, int > carToInt;
        for(int j=0; j<autom ; j++){
            string name;
            int pCatalog, pPick, pKilometer;
            cin >> name >> pCatalog >> pPick >> pKilometer;
            carToInt[name] = number;
            detailCar[number]['c'] = pCatalog;
            detailCar[number]['p'] = pPick;    
            detailCar[number]['k'] = pKilometer;
            number++;
        }
        for(int j=0; j<event; j++){
            string spy, attribute;
            int time, value;
            char state;
            cin >> time >> spy >> state >> attribute;
            if(state == 'p'){
                if(detailSpy[spy]['s'] == 0){
                    int nCar = carToInt[attribute];
                    detailSpy[spy]['s'] = 1;
                    detailSpy[spy]['c'] = nCar;
                    detailSpy[spy]['t'] += detailCar[nCar]['p'];
                }else detailSpy[spy]['s'] = 10;  
            }                      
            if(state == 'r'){
                if((detailSpy[spy]['s'] == 1) || (detailSpy[spy]['s'] == 2)){
                    detailSpy[spy]['s'] = 0;
                    int nCar = detailSpy[spy]['c'];
                    detailSpy[spy]['t'] += cStringToInt(attribute)*detailCar[nCar]['k'];
                }else detailSpy[spy]['s'] = 10;     
            } 
            if(state == 'a'){
                if((detailSpy[spy]['s'] == 1)||(detailSpy[spy]['s'] == 2)){
                    detailSpy[spy]['s'] = 2;
                    int nCar = detailSpy[spy]['c'];
                    detailSpy[spy]['t'] += (cStringToInt(attribute)*detailCar[nCar]['c']+99)/100;
                }else detailSpy[spy]['s'] = 10;     
            }     
        }
        for (std::map<string,prices>::iterator it=detailSpy.begin(); it!=detailSpy.end(); ++it){
            if(it->second['s']!=0){
                cout<< it->first << " " << "INCONSISTENT" << endl;
            }else cout<< it->first << " " << it->second['t']<< endl;
        }      
    }

	return 0;
}
