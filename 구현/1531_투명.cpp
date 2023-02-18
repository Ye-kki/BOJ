#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	int ans = 0;
	int paper[101][101] = { 0, };
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int x1, y1, x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		for (int j = x1; j <= x2; j++) {
			for (int k = y1; k <= y2; k++) {
				paper[j][k]++;
			}
		}
	}

	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (paper[i][j] > M) ans++;
		}
	}
	cout << ans;
}