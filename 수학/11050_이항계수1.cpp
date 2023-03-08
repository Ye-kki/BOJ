#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <string>

using namespace std;

long long pect(int n) {
	long long a = 1;
	for (int i = 1; i <= n; i++) {
		a *= i;
	}
	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;
	cout << pect(N) / (pect(N - K) * pect(K));
}