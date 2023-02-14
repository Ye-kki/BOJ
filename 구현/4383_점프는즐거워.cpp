#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int n;

void check(vector<int> ans) {
	for (int i = 1; i < n; i++) {
		if (ans[i] != 1) {
			cout << "Not jolly" << '\n';
			return;
		}
	}
	cout << "Jolly" << '\n';
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	


	while (cin >> n) {
		vector<int> v;
		vector<int> ans(n);

		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			v.push_back(a);
			if (i > 0 && abs(v[i] - v[i - 1]) < n) ans[abs(v[i] - v[i - 1])]++;
		}
		check(ans);
	}

}