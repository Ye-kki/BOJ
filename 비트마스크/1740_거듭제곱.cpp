#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long N, sum = 0;
	vector<long long> v;
	vector<bool> bits(40, 0);
	cin >> N;

	v.push_back(1);

	for (int i = 1; i <= 39; i++) v.push_back(v[i - 1] * 3);

	for (int i = 0; i <= 39; i++) {
		if (N & (1ULL << i)) bits[i] = true;
	}

	for (int i = 0; i <= 39; i++) {
		if (bits[i]) sum += v[i];
	}
	cout << sum;
}