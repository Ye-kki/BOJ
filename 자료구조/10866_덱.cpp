#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	deque<int> dq;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a; 
		string s;
		cin >> s;

		if (s == "push_back") {
			cin >> a;
			dq.push_back(a);
		}
		else if (s == "push_front") {
			cin >> a;
			dq.push_front(a);
		}
		else if (s == "front") {
			if (dq.empty()) cout << -1 << '\n';
			else cout << dq.front() << '\n';
		}
		else if (s == "back") {
			if (dq.empty()) cout << -1 << '\n';
			else cout << dq.back()<< '\n';
		}
		else if (s == "size") cout << dq.size() << '\n' ;
		else if (s == "empty") cout << dq.empty() << '\n';
		else if (s == "pop_front") {
			if (dq.empty()) cout << -1 << '\n';
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (s == "pop_back") {
			if (dq.empty()) cout << -1 << '\n';
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
	}
}