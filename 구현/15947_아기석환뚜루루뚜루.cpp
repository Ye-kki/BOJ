#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	int tmp = N / 14;

	if (N % 14 == 1 || N % 14 == 13) cout << "baby";
	else if (N % 14 == 2 || N % 14 == 0) cout << "sukhwan";

	else if (N % 14 == 3 || N % 14 == 7 || N % 14 == 11) {
		if (tmp < 3) {
			cout << "tururu";
			for (int i = 0; i < tmp; i++) cout << "ru";
		}
		else cout << "tu+ru*" << tmp + 2;
	}
	else if (N % 14 == 4 || N % 14 == 8 || N % 14 == 12) {
		if (tmp < 5) {
			cout << "turu";
			for (int i = 0; i < tmp; i++) cout << "ru";
		}
		else cout << "tu+ru*" << tmp + 1;
	}

	else if (N % 14 == 5) cout << "very";
	else if (N % 14 == 6) cout << "cute";
	else if (N % 14 == 9) cout << "in";
	else if (N % 14 == 10) cout << "bed";
}