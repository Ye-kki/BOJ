#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, Q;
	bool visited[1100000] = { 0, };
	vector<int> duck;

	cin >> N >> Q;

	for (int i = 0; i < Q; i++) {
		int a;
		cin >> a;
		duck.push_back(a);
	}

	for (int i = 0; i < Q; i++) {
		int tmp = duck[i];
		stack<int> s;
		while (tmp) {
			if (visited[tmp]) s.push(tmp);
			tmp /= 2;
		}
		if (s.empty()) cout << 0 << '\n';
		else cout << s.top() << '\n';
		visited[duck[i]] = true;
	}
}