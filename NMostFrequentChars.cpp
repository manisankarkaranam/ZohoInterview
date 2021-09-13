// Solution to problem 2

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compareFreqOrder(pair<int, int> p1, pair<int, int> p2)
{
	if (p1.second != p2.second)
		return p1.second > p2.second;
	else return p1.first < p2.first;
}

string getNMostFrequent(string original, int n) {
	string str = original;
	transform(str.begin(), str.end(), str.begin(), ::tolower);

	vector<pair<int, int>> freq;
	for (int i = 0; i < 26; i++)
		freq.push_back({ i, 0 });

	for (int i = 0; i < str.size(); i++) {
		if (str[i] - 'a' >= 0 && str[i] - 'a' < 26)
			freq[str[i] - 'a'].second++;
	}
	sort(freq.begin(), freq.end(), compareFreqOrder);

	string result;
	for (int i = 0; i < min(n, 26); i++) {
		if (freq[i].second == 0) break;
		char tmp = freq[i].first + 'a';
		result += tmp;
	}
	return result;
}

int main()
{
	string str = "";
	int topN = 5;
	string result = getNMostFrequent(str, topN);
	cout << "Top " << topN << " frequent characters are " << "'" << result << "'" << endl;
	return 0;
}

/*
1. ""
2. "he"
3. "hello"
4. "Hello World"
5. "Hhhhhh"
*/
