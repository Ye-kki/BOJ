#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	vector<int> v;
	vector<int> gap;
	int sum = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	for (int i = 0; i < N - 1; i++) gap.push_back(v[i + 1] - v[i]);

	int a = gap[0];
	for (int i = 1; i < gap.size(); i++) a = gcd(a, gap[i]);
	for (int i = 0; i < gap.size(); i++) sum += gap[i] / a - 1;

	cout << sum;
}