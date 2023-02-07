#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	queue<int> q;
	vector<int> v;
	cin >> N >> K;

	for (int i = 1; i <= N; i++) q.push(i);

	while (!q.empty()) {
		for (int i = 0; i < K-1; i++) {
			q.push(q.front());
			q.pop();
		}
		v.push_back(q.front());
		q.pop();
	}

	cout << "<";
	for (int i = 0; i < v.size() - 1; i++) cout << v[i] << ", ";
	cout << v[v.size() - 1] << ">";
}