#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int N;
set<char> alpha;
string s;

void chk() {
	for (int i = 0; i < s.size(); i++) {
		if (i == 0 || s[i - 1] == ' ') {
			char tmp = s[i];
			if (s[i] >= 'A' && s[i] <= 'Z') tmp = tolower(s[i]);
			if (alpha.find(tmp) != alpha.end()) continue;
			else {
				alpha.insert(tmp);
				s.insert(i, "[");
				s.insert(i + 2, "]");
				cout << s << '\n';
				return;
			}
		}
	}
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != ' ') {
			char tmp = s[i];
			if (s[i] >= 'A' && s[i] <= 'Z') tmp = tolower(s[i]);
			if (alpha.find(tmp) != alpha.end()) continue;
			else {
				alpha.insert(tmp);
				s.insert(i, "[");
				s.insert(i + 2, "]");
				cout << s << '\n';
				return;
			}
		}
	}
	cout << s << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;
	cin.ignore();

	while (N--) {
		getline(cin, s);
		chk();
	}
}