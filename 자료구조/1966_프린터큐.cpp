#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T, N, idx;
	cin >> T;

	while (T--) {
		int importance[10] = { 0, };
		queue<pair<int,int>> q;
		int maxN = 0;
		int cnt = 0;

		cin >> N >> idx;

		for (int i = 0; i < N; i++) {
			int a;
			cin >> a;
			importance[a]++;
			q.push({a,i});
		}

		while (!q.empty()) {
			for (int i = 9; i >= 1; i--) {//최댓값
				if (importance[i]) {
					maxN = i;
					break;
				}
			}
			if (q.front().first != maxN) {
				q.push(q.front());
				q.pop();
			}
			else {
				cnt++;
				if (q.front().second == idx) {
					cout << cnt << '\n';
					break;
				}
				q.pop();
				importance[maxN]--;
			}
		}
	}
}
 