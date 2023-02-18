#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

unsigned long long long_pow(int a, int b) {
	unsigned long long tmp = 1;
	for (int i = 0; i < b; i++) tmp *= a;
	return tmp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	unsigned long long A, B;
	bool eratos[10000100] = { 0, };
	vector<int> prime;
	vector<unsigned long long> prime_sqrt;
	int start = 0 , end = 670121;
	cin >> A >> B;

	eratos[0] = 1;
	for (int i = 2; i <= sqrt(10000100); i++) {
		int tmp = i;
		int idx = 2;
		while (tmp * idx < 10000100) {
			eratos[tmp * idx] = 1;
			idx++;
		}
	}

	for (int i = 2; i <= 10000100; i++) {
		if (!eratos[i]) prime.push_back(i);
	}

	for (int i = 0; i < prime.size(); i++) {
		int tmp = 2;
		for (int j = 0; j < 50; j++) {
			unsigned long long num = long_pow(prime[i], tmp);
			if (num > 1e14 || num < 4 || (prime_sqrt.size() > 0 && j > 0 && num % prime_sqrt[prime_sqrt.size() - 1] )) break;
			prime_sqrt.push_back(num);
			tmp++;
		}
	}

	sort(prime_sqrt.begin(), prime_sqrt.end());
	for (int i = 0; i < prime_sqrt.size(); i++) {
		if (prime_sqrt[i] >= A) {
			start = i;
			break;
		}
	}
	for (int i = start; i < prime_sqrt.size(); i++) {
		if (prime_sqrt[i] > B) {
			end = i;
			break;
		}
	}

	cout << end - start;
}