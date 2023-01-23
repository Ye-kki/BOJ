#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, D;
vector<int> v;

bool is_possible(int mid) {
	if (v[mid] >= D) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < M; i++) {
		cin >> D;

		int left = 0, right = v.size() - 1, ret = -1;

		while (left <= right) {
			int mid = (left + right) / 2;

			if (is_possible(mid)) {
				if (v[mid] == D) ret = mid;
				right = mid - 1;
			}
			else left = mid + 1;
		}
		cout << ret << '\n';
	}
}