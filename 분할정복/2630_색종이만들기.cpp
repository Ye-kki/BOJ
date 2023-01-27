#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
int board[200][200] = { 0, };
int paper[2] = { 0, };

void partition(int y, int x, int n) {
	bool chk = true;
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (board[x][y] != board[i][j]) chk = false;
		}
	}

	if (chk) paper[board[x][y]]++;
	else {
		partition(y, x, n / 2);
		partition(y + (n / 2), x, n / 2);
		partition(y, x + (n / 2), n / 2);
		partition(y + (n / 2), x + (n / 2), n / 2);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> board[i][j];
	}

	partition(0, 0, N);
	cout << paper[0] << '\n' << paper[1];
}