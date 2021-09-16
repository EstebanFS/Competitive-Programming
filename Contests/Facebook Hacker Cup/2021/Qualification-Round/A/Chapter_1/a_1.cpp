#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

#define ALPHA 30
#define pcc pair<char, char>
#define D(x) cout << #x << " " << x << endl

bool isConsistent(string &word) {
	bool consistent = true;
	for(int i = 1; i < word.size() && consistent; ++i) {
		if(word[i] != word[i - 1]) consistent = false;
	}
	return consistent;
}

bool isVowel(char x) {
	if(x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U') return true;
	return false;
}

pcc getHigherVowelAndConsonant(string &word) {
	int maxVowels = 0, maxConsonants = 0, hVowel = 'A', hConsonant = 'B';
	vector<int> fLetter(ALPHA, 0);
	for(int i = 0; i < word.size(); ++i) fLetter[word[i] - 'A']++;
	for(int i = 0; i < ALPHA; ++i) {
		if(isVowel('A' + i) && maxVowels < fLetter[i]) {
			maxVowels = fLetter[i];
			hVowel = 'A' + i;
		} else if(!isVowel('A' + i) && maxConsonants < fLetter[i]) {
			maxConsonants = fLetter[i];
			hConsonant = 'A' + i;
		}
	}
	return pcc(hVowel, hConsonant);
}

int transformEqual(string &word, char final) {
	int cost = 0;
	for(int i = 0; i < word.size(); ++i) {
		if(word[i] == final) continue;
		cost += (isVowel(word[i]) == isVowel(final)) + 1;
	}
	return cost;
}

int makeItConsitent(string &word) {
	if(isConsistent(word)) return 0;
	pcc hvc = getHigherVowelAndConsonant(word);
	int minToVowel = transformEqual(word, hvc.first);
	int minToConsonant = transformEqual(word, hvc.second);
	return min(minToVowel, minToConsonant);
}

int main() {
	int t;
	string word;
	cin >> t;
	for(int x = 1; x <= t; ++x) {
		cin >> word;
		printf("Case #%d: %d\n", x, makeItConsitent(word));
	}
	return 0;
}
