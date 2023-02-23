#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	stack<pair<int, int>> stk;
	cin >> N;
	vector<int> v(N);
	vector<int> arr(N,0);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	for (int i = v.size()-1; i >=0; i--) {
		while (!stk.empty()) {
			pair<int, int> p = stk.top();
			if (p.first >= v[i]) break;
			else {
				arr[p.second] = i + 1;
				stk.pop();
			}
		}
		stk.push({ v[i],i });
	}
	for (int i = 0; i < N; i++) {
		cout << arr[i] << ' ';
	}
}