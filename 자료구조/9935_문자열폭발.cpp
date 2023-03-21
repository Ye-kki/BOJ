#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str, boom;
	stack<char> s2;
	vector<char> v;
	vector<char> s1;

	cin >> str >> boom;
	
	if (str.size() < boom.size()) {
		cout << str;
		return 0;
	}
	for (int i = 0; i < str.size(); i++) {
		s1.push_back(str[i]);
		bool chk = true;

		if (str[i] == boom[boom.size() - 1]) {//마지막 단어면
			for (int j = 0; j < boom.size(); j++) {//같은 지 확인
				if (s1[s1.size() - j -1] != boom[boom.size() - j - 1]) {
					chk = false;
					break;
				}
			}
			if (chk) {
				for (int j = 0; j < boom.size(); j++) s1.pop_back();
			}
		}
	}

	if (!s1.size()) {
		cout << "FRULA";
		return 0;
	}
	for (int i = 0; i < s1.size(); i++) cout << s1[i];
}