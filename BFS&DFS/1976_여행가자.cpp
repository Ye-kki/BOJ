#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

int N, M;
vector<int> chk;
vector<vector<int>> v;
int visited[202] = { 0, };
unordered_map<int, int> ump;

void bfs(int u) {
	queue<int> q;
	q.push(u);
	visited[u] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < v[now].size(); i++) {
			if (visited[v[now][i]]) continue;

			visited[v[now][i]] = 1;
			q.push(v[now][i]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	v.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < N; j++) {
			int a;
			cin >> a;
			if (a) v[i].push_back(j+1);
		}
	}
	for (int i = 0; i < M; i++) {
		int a;
		cin >> a;
		ump[a] = 1;
	}
	for (auto i : ump) {
		bfs(i.first);
		break;
	}
	for (auto i : ump) {
		if (!visited[i.first]) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
