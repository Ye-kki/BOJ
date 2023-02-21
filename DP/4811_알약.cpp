#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int N;
long long cache[31][62];

long long dp(int idx, int cnt) {
	if (idx == 0 && cnt == 0) return 1;

	long long& ret = cache[idx][cnt];
	if (ret != -1) return ret;
	ret = 0;

	if (cnt && idx) ret = dp(idx, cnt - 1) + dp(idx - 1, cnt + 1); //둘다 있을때
	else if (!idx) ret = dp(idx, cnt - 1); //반개만 있을 때
	else ret = dp(idx - 1, cnt + 1); //큰거만 있을때

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(cache, -1, sizeof(cache));

	cin >> N;

	while (N) {
		cout << dp(N, 0) << '\n';
		cin >> N;
	}
}