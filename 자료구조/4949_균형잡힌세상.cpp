#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	getline(cin, s);

	while (s != ".") {
		stack<char> bracket;
		for (int i = 0; i < s.size(); i++) {
			if (!bracket.empty()) {
				if (bracket.top() == '(' && s[i] == ')') {
					bracket.pop();
					continue;
				}
				else if (bracket.top() == '[' && s[i] == ']') {
					bracket.pop();
					continue;
				}
			}
			if (s[i] == '(' || s[i] == '['|| s[i] == ')' || s[i] == ']') bracket.push(s[i]);
		}
		if (bracket.empty()) cout << "yes" << '\n';
		else cout << "no" << '\n';

		getline(cin, s);
	}
}