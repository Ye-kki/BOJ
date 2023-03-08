#include <iostream>
#include <cmath>

using namespace std;

long long int_pow(long long a, long long b) {
	long long tmp = 1;
	while (b--) {
		tmp *= a;
		tmp %= 1234567891;
	}
	return tmp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	long long sum = 0;
	string s;
	cin >> n >> s;

	for (int i = 0; i < s.size(); i++) {
		sum += (s[i] - 'a' + 1)* int_pow(31, i);
		sum %= 1234567891;
	}

	cout << sum;
}
 