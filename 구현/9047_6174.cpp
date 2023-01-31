#include <iostream>
#include <string.h>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	int n;
	cin >> T;

	while (T--) {
		cin >> n;
		int cnt = 0;
		while (n != 6174) {
			int maxN = 0, minN = 0;
			int arr[4];
			for (int i = 0; i < 4; i++) {
				arr[i] = n % 10;
				n /= 10;
			}

			sort(arr, arr + 4);

			for (int i = 0; i < 4; i++) {
				minN *= 10;
				minN += arr[i];
				maxN *= 10;
				maxN += arr[3 - i];
			}

			n = maxN - minN;
			cnt++;
		}
		cout << cnt << '\n';
	}
}