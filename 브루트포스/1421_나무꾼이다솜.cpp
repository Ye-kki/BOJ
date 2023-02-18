#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, C, W;
	long long sum = 0;
	cin >> N >> C >> W;

	vector<int> v(N);

	for (int i = 0; i < N; i++) cin >> v[i];
	sort(v.begin(), v.end());

	for (int i = 1; i <= v[v.size() - 1]; i++) {
		long long tmp = 0;
		for (int j = 0; j < N; j++) {
			long long cnt = (v[j] / i * W * i) - (((v[j] - 1) / i) * C);
			if (cnt > 0) tmp += cnt;
		}
		sum = max(sum, tmp);
	}

	cout << sum;
}