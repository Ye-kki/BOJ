#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int M, N, P, HP;
char board[1001][1001];
int visited[1001][1001][27] = { 0, };
int alpha[26] = { 0, };
int goY[4] = { 1,-1,0,0 }, goX[4] = { 0,0,1,-1 };
unordered_map<char, int> player;

bool is_in_board(int y, int x) {
	if (y < 0 || x < 0 || y >= M || x >= N) return false;
	return true;
}

void bfs(int y, int x, char c) {
	queue<pair<int, int>> q;
	q.push({ y,x });
	visited[y][x][c] = 1;

	while (!q.empty()) {
		int nowY = q.front().first, nowX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = nowY + goY[i], nextX = nowX + goX[i];

			if (!is_in_board(nextY, nextX)) continue;
			if (board[nextY][nextX] == 'X') continue;
			if (visited[nextY][nextX][c]) continue;
			if (board[nextY][nextX] == 'B') {
				alpha[c - 'a'] = visited[nowY][nowX][c];
				return;
			}
			visited[nextY][nextX][c] = visited[nowY][nowX][c] + 1;
			q.push({ nextY, nextX });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N >> P;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) cin >> board[i][j];
	}
	for (int i = 0; i < P; i++) {
		char c;
		int a;
		cin >> c >> a;
		player.insert({ c,a });
	}
	cin >> HP;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] >= 'a' && board[i][j] <= 'z') bfs(i, j, board[i][j]);
		}
	}
	while (HP>0) {
		for (int j = 1; j <= 1000000; j++) {
			int cnt = 0;
			for (int i = 0; i < 26; i++) {
				if (alpha[i] <= j && alpha[i] > 0) {
					HP -= player[i + 'a'];
					cnt++;
				}
			}
			if (HP <= 0) {
				cout << cnt;
				return 0;
			}
		}
	}

}