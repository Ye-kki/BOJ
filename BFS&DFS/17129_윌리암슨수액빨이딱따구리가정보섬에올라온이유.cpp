#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int n, m;
int board[3001][3001] = { 0, };
int visited[3001][3001] = { 0, };
int goY[4] = { 0,0,1,-1 }, goX[4] = { 1,-1,0,0 };
pair<int, int> start;

bool is_in_board(int y, int x) {
	if (y < 0 || x < 0 || y >= n || x >= m) return false;
	return true;
}

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y,x });
	visited[y][x] = 1;

	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			pair<int, int> next = { now.first + goY[i], now.second + goX[i] };

			if (!is_in_board(next.first, next.second)) continue;
			if (visited[next.first][next.second]) continue;
			if (board[next.first][next.second] == 1) continue;

			visited[next.first][next.second] = visited[now.first][now.second] + 1;

			if (board[next.first][next.second] == 3 || board[next.first][next.second] == 4 || board[next.first][next.second] == 5){
				cout << "TAK" << '\n';
				cout << visited[next.first][next.second] - 1;
				return;
			}
			
			q.push({ next.first, next.second });
		}
	}
	cout << "NIE";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			board[i][j] = s[j] - '0';
			if (board[i][j] == 2) start = { i,j };
		}
	}

	bfs(start.first, start.second);
}