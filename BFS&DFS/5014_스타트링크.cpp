#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int F, S, G, U ,D;
int visited[1000002] = { 0, };

void bfs(int s) {
	queue<int> q;
	q.push(s);
	visited[s] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < 2; i++) {
			int next;
			if (i == 0) next = now + U;
			else next = now - D;

			if (next < 1 || next > F) continue;
			if (visited[next]) continue;
			
			visited[next] = visited[now] + 1;

			if (next == G) {
				cout << visited[next] - 1;
				return;
			}
			q.push(next);
		}
	}
	cout << "use the stairs";
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> F >> S >> G >> U >> D;
	if (S == G) {
		cout << 0;
		return 0;
	}
	bfs(S);
}