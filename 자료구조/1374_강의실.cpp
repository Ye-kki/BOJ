#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return a.second < b.second;
	else return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int, vector<int>,greater<int>> pq;
	vector<pair<int, int>> v;
	int N;
	int cnt = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ b,c });
	}
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
		cnt = max(cnt, (int)pq.size());
	}

	cout << cnt;
}