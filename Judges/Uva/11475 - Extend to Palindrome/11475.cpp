//Esteban Foronda Sierra
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> preKmp(string needle){
   int m = needle.size();
   vector<int> border(m);
   border[0] = 0;

   for (int i = 1; i < m; ++i) {
      border[i] = border[i - 1];
      while (border[i] > 0 and needle[i] != needle[border[i]])
         border[i] = border[border[i] - 1];
      if (needle[i] == needle[border[i]]) border[i]++;
   }
   return border;
}

int main() {
	string x;
	while(cin >> x) {
		string revx = x;
		reverse(revx.begin(), revx.end());
		string text = revx + "&" + x;
		vector<int> border = preKmp(text);
		int start = border[text.size() - 1];
		cout << x + revx.substr(start) << endl;
	}
	return 0;
}
