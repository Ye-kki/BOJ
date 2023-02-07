#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int maxN = 0;
	stack<char> s;

	cin >> N;

	for (int i = 0; i < N; i++) {
		char c;
		cin >> c;

		if (!s.empty() && s.top() == '(' && c == ')') s.pop();
		else if (!s.empty() && s.top() == ')' && c == '(') s.pop();
		else s.push(c);
		maxN = max(maxN, (int)s.size());
	}


	if (!s.empty()) cout << -1;
	else cout << maxN;
}