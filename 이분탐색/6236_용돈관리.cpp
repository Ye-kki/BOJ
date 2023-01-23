#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v;

bool is_possible(int mid) {
	int cnt = 1;
	int tmp = mid;

	for (int i = 0; i < v.size(); i++) {
		if (mid < v[i]) return false;
		if (tmp - v[i] < 0) {
			cnt++;
			tmp = mid;
		}
		tmp -= v[i];
	}

	if (cnt <= M) return true;
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

	int left = 1, right = 1e9 + 2, ret = -1;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (is_possible(mid)) {
			ret = mid;
			right = mid - 1;
		}
		else left = mid + 1;
	}
	cout << ret;
}