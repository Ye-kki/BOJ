#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int,int> b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	vector<pair<int,int>> v;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < N; i++) {
		cout << v[i].first << ' ' << v[i].second << '\n';
	}
}
 