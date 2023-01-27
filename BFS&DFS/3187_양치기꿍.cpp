#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int R,C;
int board[252][252] = { 0, };
int visited[252][252] = { 0, };
int goY[4] = { 0,0,1,-1 }, goX[4] = { -1,1,0,0 };
int sheep = 0, wolf = 0;
int sheep_cnt = 0, wolf_cnt = 0;

bool is_in_board(int y, int x) {
	if (y < 0 || x < 0 || y >= R || x >= C) return false;
	return true;
}

void bfs(int y, int x) {
	if (visited[y][x]) return;

	queue<pair<int, int>> q;
	q.push({ y,x });
	visited[y][x] = 1;
	if(board[y][x] == 2) wolf_cnt++;
	else sheep_cnt++;

	while (!q.empty()) {
		pair<int, int> now = q.front();

		q.pop();

		for (int i = 0; i < 4; i++) {
			pair<int, int> next = { now.first + goY[i] , now.second + goX[i] };

			if (!is_in_board(next.first , next.second)) continue;
			if (!board[next.first][next.second]) continue;
			if (visited[next.first][next.second]) continue;

			if (board[next.first][next.second] == 2) wolf_cnt++;
			else if (board[next.first][next.second] == 3) sheep_cnt++;

			visited[next.first][next.second] = 1;
			q.push({ next.first , next.second });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < C; j++) {
			if (s[j] == '.') board[i][j] = 1;
			else if (s[j] == 'v') board[i][j] = 2;
			else if (s[j] == 'k') board[i][j] = 3;
			else board[i][j] = 0;
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j] == 3 || board[i][j] == 2) {
				sheep_cnt = 0;
				wolf_cnt = 0;
				bfs(i, j);
				if (wolf_cnt >= sheep_cnt) wolf += wolf_cnt;
				else sheep += sheep_cnt;
			}

		}
	}
	cout << sheep << ' ' << wolf;
}