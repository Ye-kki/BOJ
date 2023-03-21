#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int T, N;
vector<pair<string, string>> v;
vector<int> parent;
unordered_map<string, int> name;

int Find(int x) { //부모 찾는 함수
	if (parent[x] < 0) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x == y) return;
	if (parent[x] <= parent[y]) {
		parent[x] = parent[x] + parent[y];
		parent[y] = x;
	}
	else {
		parent[y] = parent[x] + parent[y];
		parent[x] = y;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	while (T--) {
		cin >> N;
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			string a, b;
			cin >> a >> b;
			v.push_back({ a,b });
			if (name.find(a) == name.end()) {
				name[a] = cnt;
				cnt++;
			}
			if (name.find(b) == name.end()) {
				name[b] = cnt;
				cnt++;
			}
		}
		for (int i = 0; i < name.size(); i++) parent.push_back(-1);
		for (int i = 0; i < N; i++) {
			Union(name[v[i].first], name[v[i].second]);
			cout << parent[Find(name[v[i].first])] * -1 << '\n';
		}

		parent.clear();
		name.clear();
		v.clear();
	}
}