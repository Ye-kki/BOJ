#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> v;
	queue<int> q;
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) q.push(i);

	while (q.size() > 1) {
		v.push_back(q.front());
		q.pop();
		q.push(q.front());
		q.pop();
	}

	for (auto i : v) cout << i << ' ';
	cout << q.front();
}