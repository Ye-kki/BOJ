#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int maxN = 0;
	priority_queue<int, vector<int>, greater<int>> pq;

	cin >> N;

	vector<pair<int, int>> v(N);

	for (int i = 0; i < N; i++) cin >> v[i].first >> v[i].second;

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < N; i++) {
		if (pq.empty()) pq.push(v[i].second);
		else {
			if (pq.top() <= v[i].first) {
				pq.pop();
				pq.push(v[i].second);
			}
			else pq.push(v[i].second);
		}
		maxN = max(maxN, (int)pq.size());
	}
	cout << maxN;
}
 