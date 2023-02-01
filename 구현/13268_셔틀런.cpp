#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	int tmp = N % 100;

	if (tmp > 75 && tmp < 85) cout << 4;
	else if ((tmp > 40 && tmp < 50) || (tmp > 70 && tmp <= 75) || (tmp >= 85 && tmp < 90)) cout << 3;
	else if ((tmp > 15 && tmp < 25) || (tmp > 35 && tmp <= 40) || (tmp >= 50 && tmp < 55) || (tmp > 65 && tmp <= 70) || (tmp >= 90 && tmp < 95)) cout << 2;
	else if (tmp == 0 || tmp == 10 || tmp == 30 || tmp == 60) cout << 0;
	else cout << 1;
}