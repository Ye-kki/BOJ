#include <iostream>
#include <cmath>
using namespace std;

int N;
int paper[2200][2200] = { 0, };
int cnt[3] = { 0, };

void partition(int x, int y, int n) {
	int tmp = paper[x][y];
	int tmp_cnt = 0;

	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (tmp != paper[i][j]) {
				tmp_cnt++;
			}
		}
	}

	if (!tmp_cnt) cnt[paper[x][y] + 1]++;
	else {
		partition(x, y, n / 3);

		partition(x, y + n / 3, n / 3);
		partition(x, y + n / 3 * 2, n / 3);

		partition(x + n / 3, y, n / 3);
		partition(x + n / 3 * 2, y, n / 3);

		partition(x + n / 3, y + n / 3, n / 3);
		partition(x + n / 3 * 2, y + n / 3, n / 3);
		partition(x + n / 3, y + n / 3 * 2, n / 3);
		partition(x + n / 3 * 2, y + n / 3 * 2, n / 3);
	}
	return;

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> paper[i][j];
	}

	partition(0, 0, N);

	for (int i = 0; i < 3; i++) cout << cnt[i] << '\n';
}