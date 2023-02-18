#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	int minN = 987654321;
	int b = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'b') b++;
	}

	for (int i = 0; i < s.size(); i++) {
		int tmp = 0;
		for (int j = i; j < i + b; j++) {
			if (j > s.size() - 1) {
				if (s[j - s.size()] != 'b') tmp++;
			}
			else {
				if (s[j] != 'b') tmp++;
			}
		}
		minN = min(minN, tmp);
	}

	cout << minN;
}