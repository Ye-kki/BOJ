#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int T, N, M;
int cache[21][10002];
vector<int> v;

int dp(int idx, int sum){
	if (sum > M) return 0;
	if (idx >= N) return 0;
	if (sum == M) return 1;

	int& ret = cache[idx][sum];
	if (ret != -1) return ret;
	ret = 0;

	ret = dp(idx, sum + v[idx]) + dp(idx + 1, sum);

	return ret;
}

int main() {
	cin >> T;

	while (T--) {
		cin >> N;
		memset(cache, -1, sizeof(cache));
		
		for (int i = 0; i < N; i++) {
			int a;
			cin >> a;
			v.push_back(a);
		}

		cin >> M;

		cout << dp(0, 0) << '\n';
		v.clear();
	}

}