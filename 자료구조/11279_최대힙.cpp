#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int> pq;
	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (!a) {
			if (pq.empty()) cout << 0 << '\n';
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else pq.push(a);
	}

}
 