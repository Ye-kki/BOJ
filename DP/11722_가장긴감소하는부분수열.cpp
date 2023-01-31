#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int N;
int cache[1002][1002];
int arr[1002];

int dp(int idx, int last) {
	if (idx == N) return 0;

	int& ret = cache[idx][last];
	if (ret != -1) return ret;
	ret = 0;

	if (last > arr[idx]) ret = max(dp(idx + 1, arr[idx]) + 1, dp(idx + 1, last));
	else ret = dp(idx + 1, last);

	return ret;
}


int main() {
	cin >> N;
	memset(cache, -1, sizeof(cache));

	for (int i = 0; i < N; i++) cin >> arr[i];

	cout << dp(0, 1001);
}