#include <iostream>
#include <deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	deque<int> dq;

	cin >> N;
	for (int i = 1; i <= N; i++) dq.push_back(i);

	while (dq.size() != 1) {
		dq.pop_front();
		int tmp = dq.front();
		dq.pop_front();
		dq.push_back(tmp);
	}

	cout << dq.front();
}