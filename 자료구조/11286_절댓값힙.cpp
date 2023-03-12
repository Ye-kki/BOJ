#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		if (abs(a) == abs(b)) return a > b; //정렬이 아닌 우선순위
		else return abs(a) > abs(b);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int, vector<int>, cmp> pq;
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
 