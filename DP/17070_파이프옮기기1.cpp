#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int board[17][17] = { 0, };
int cache[20][20][3];
int N;

int dp(int y,int x, int last) {
	if (y >= N || x >= N) return 0;
	if (board[y][x] == 1) return 0; //가로 세로
	if (last == 1 && (board[y - 1][x] == 1 || board[y][x - 1] == 1 || board[y][x] == 1)) return 0;
	if (y == N - 1 && x == N - 1) return 1;

	int& ret = cache[y][x][last];
	if (ret != -1) return ret;

	if (last == 0) { //가로
		ret = dp(y, x + 1, 0) + dp(y + 1, x + 1, 1);
	}
	else if (last == 1) { //대각선
		ret = dp(y, x + 1, 0) + dp(y + 1, x + 1, 1)+ dp(y + 1, x, 2);
	}
	else {//세로
		ret = dp(y + 1, x + 1, 1) + dp(y + 1, x, 2);
	}


	return ret;
}

int main() {
	cin >> N;

	memset(cache, -1, sizeof(cache));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	cout << dp(0, 1, 0);

}