#include <iostream>
#include <deque>
#include <string>

using namespace std;

void func(string p, deque<int> &deq) {
	bool reverse = false;

	for (int i = 0; i < p.size(); i++) {
		if (p[i] == 'R') {
			reverse = !reverse;
			continue;
		}
		if (!deq.empty() && p[i] == 'D') {
			if (reverse) deq.pop_back();
			else deq.pop_front();
		}
		else {
			cout << "error" << '\n';
			return;
		}
	}

	if (reverse) {
		cout << '[';
		while (!deq.empty()) {
			cout << deq.back();
			if (deq.size() > 1) cout << ',';
			deq.pop_back();
		}
		cout << ']' << '\n';
	}
	else {
		cout << '[';
		while (!deq.empty()) {
			cout << deq.front();
			if (deq.size() > 1) cout << ',';
			deq.pop_front();
		}
		cout << ']' << '\n';
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		deque<int> deq;
		string p, s;
		int n;
		
		cin >> p >> n >> s;

		for (int i = 1; i < s.size() - 1; i++) {
			if (s[i] >= '0' && s[i] <= '9') {
				int idx = i;
				for (int j = i + 1; j < s.size(); j++) {
					if (s[j] < '0' || s[j] > '9') {
						deq.push_back(stoi(s.substr(idx, j - idx)));
						i = j;
						break;
					}
				}
			}
		}
		
		func(p, deq);
	}
}