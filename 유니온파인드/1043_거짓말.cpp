#include <iostream>
#include <vector>

using namespace std;

int N, M, k;
int sum = 0;
vector<int> parent;
vector<int> truth;
vector<vector<int>> v;

int Find(int x) { //부모 찾는 함수
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x == y) return;

	if(truth[y]) parent[x] = y;
	else parent[y] = x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> k;
	v.resize(M);
	parent.push_back(0);
	truth.resize(N + 1);

	for (int i = 0; i <= N; i++) truth[i] = 0;
	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
		truth[a] = 1;
	}

	for (int i = 1; i <= N; i++) parent.push_back(i);

	for (int i = 0; i < M; i++) {
		int cnt;
		cin >> cnt;
		v[i].resize(cnt);
		for (int j = 0; j < cnt; j++) cin >> v[i][j];
		for (int j = 1; j < cnt; j++) Union(parent[v[i][0]], parent[v[i][j]]);
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			if (truth[Find(v[i][j])]) {
				sum++;
				break;
			}
		}
	}
	cout << M - sum;
}