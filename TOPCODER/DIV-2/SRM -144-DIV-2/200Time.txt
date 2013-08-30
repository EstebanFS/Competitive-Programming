#include <iostream>
#include <string>
#include <sstream>

using namespace std;

 class Time{
public: string whatTime(int seconds){
		int h= seconds/3600;
		seconds = seconds - (h*3600);
		int m= seconds/60;
		seconds = seconds -(m*60);
		string total;
		stringstream stream,stream1,stream2;
		stream  << h; 
		total=stream.str()+ ":";
		stream1 << m; 
		total=total+stream1.str()+ ":";
		stream2  << seconds; 
		total=total + stream2.str();
		return total;
		
			
	}
};