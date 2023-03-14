#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int N, M, k;
int visited[10001] = { 0, };
int sum = 0;
vector<pair<int, int>> parent;
unordered_map<int, int> ump;

int Find(int x) { //부모 찾는 함수
	if (parent[x].first == x) return x;
	return parent[x].first = Find(parent[x].first);
}

void Union(int x, int y) { //비용이 작은 것을 부모로 연결
	x = Find(x);
	y = Find(y);
	if (x != y) {
		if (parent[x].second >= parent[y].second) parent[x].first = y;
		else parent[y].first = x;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> k;
	parent.push_back({ 0,0 });

	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		parent.push_back({ i,a });
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		Union(a, b);
	}

	for (int i = 1; i <= N; i++) {
		Find(i); //부모 통일
		if(ump[parent[i].first]) ump[parent[i].first] = min(ump[parent[i].first], parent[i].second);
		else ump[parent[i].first] = parent[i].second;
	}

	for (auto i : ump) {
		sum += i.second;
		if (sum > k) {
			cout << "Oh no";
			return 0;
		}
	}
	cout << sum;
}