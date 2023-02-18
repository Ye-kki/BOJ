#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int A, B;
	int eratos[100001] = { 0, };
	int ans = 0;
	vector<int> prime;
	cin >> A >> B;

	eratos[1] = 1;
	for (int i = 2; i <= sqrt(100000); i++) {
		int tmp = 2;
		while (tmp * i <= 100000) {
			eratos[tmp * i]++;
			tmp++;
		}
	}

	for (int i = 2; i <= 100000; i++) {
		if (!eratos[i]) prime.push_back(i);
	}

	for (int i = A; i <= B; i++) {
		int tmp = i;
		int idx = 0;
		int cnt = 0;
		while (tmp != 1) {
			if (tmp % prime[idx]) idx++;
			else {
				tmp /= prime[idx];
				cnt++;
			}
		}
		if (!eratos[cnt]) ans++;
	}

	cout << ans;
}