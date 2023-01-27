#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	char board[51][51];
	char board_B[51][51];
	char board_W[51][51];
	int minN = 987654321;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if ((i + j) % 2) { //홀수일때
				board_B[i][j] = 'W'; 
				board_W[i][j] = 'B';
			}
			else { //짝수일때
				board_B[i][j] = 'B';
				board_W[i][j] = 'W';
			}
		}
	}

	for (int i = 0; i < N - 7; i++) {
		for (int j = 0; j < M - 7; j++) {
			int diff_B = 0;
			int diff_W = 0;
			for (int k = i; k < i + 8; k++) {
				for (int l = j; l < j + 8; l++) {
					if (board[k][l] != board_B[k][l]) diff_B++;
					if (board[k][l] != board_W[k][l]) diff_W++;
				}
			}
			int tmp = min(diff_B, diff_W);
			minN = min(minN, tmp);
		}
	}

	cout << minN;

}