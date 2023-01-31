#include <iostream>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int N, M;
int board[101] = { 0, };
int visited[101] = { 0, };

unordered_map<int, int> ladder;
unordered_map<int, int> snake;

int bfs(int y) {
	queue<int> q;
	q.push(y);
	visited[y] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 1; i <= 6; i++) {
			int next = now + i;

			if (next > 100) continue;
			if (next == 100) return visited[next] = visited[now] + 1;

			if (visited[next] != 0) continue;

			if (board[next] == 2) { // 사다리
				visited[next] = visited[now] + 1;
				if (visited[ladder[next]] != 0) continue;
				visited[ladder[next]] = visited[next];
				q.push(ladder[next]);
				continue;
			}
			if (board[next] == 3){ // 뱀
				visited[next] = visited[now] + 1;
				if (visited[snake[next]] != 0) continue;
				visited[snake[next]] = visited[next];
				q.push(snake[next]);
				continue;
			}

			visited[next] = visited[now] + 1;
			q.push(next);
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		pair<int, int> p;
		cin >> p.first >> p.second;
		board[p.first] = 2; // 사다리
		ladder.insert(p);
	}
	for (int i = 0; i < M; i++) {
		pair<int, int> p;
		cin >> p.first >> p.second;
		board[p.first] = 3; // 뱀
		snake.insert(p);
	}

	cout << bfs(1) - 1;
	
}