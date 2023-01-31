#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

const int MOD = 1000000009;
int N, T;
long long cache[1000001];

long long dp(long long idx) {
	if (idx == 0) return 1;
	if (idx < 0) return 0;

	long long& ret = cache[idx];
	if (ret != -1) return ret % MOD;
	ret = 0;

	ret = dp(idx - 1) + dp(idx - 2) + dp(idx - 3);

	return ret %= MOD;
}


int main() {
	cin >> T;
	memset(cache, -1, sizeof(cache));

	while (T--) {
		cin >> N;
		cout << dp(N) % MOD << '\n';
	}

}