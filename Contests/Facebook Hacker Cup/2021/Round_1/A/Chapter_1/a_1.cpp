#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

#define ALPHA 30
#define pcc pair<char, char>
#define D(x) cout << #x << " " << x << endl

int minSwitch(string &word) {
	char lastHand = 'Z';
	int ans = 0;
	for(int i = 0; i < word.size(); ++i) {
		if(word[i] == 'F') continue;
		if(lastHand != 'Z' && lastHand != word[i]) ans++;
		lastHand = word[i];
	}
	return ans;
}

int main() {
	int t, n;
	string word;
	cin >> t;
	for(int x = 1; x <= t; ++x) {
		cin >> n >> word;
		printf("Case #%d: %d\n", x, minSwitch(word));
	}
	return 0;
}
