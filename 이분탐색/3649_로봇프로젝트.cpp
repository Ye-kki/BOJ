#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int x;
	while (cin >> x) {
		x *= 10000000;
		int n;
		bool chk = false;
		cin >> n;
		
		vector<int> v(n);
		for (int i = 0; i < n; i++) cin >> v[i];

		sort(v.begin(), v.end());

		int left = 0, right = n - 1, sum;

		while (left < right) {
			sum = v[left] + v[right];
			if (sum == x) {
				chk = true;
				cout << "yes " << v[left] << " " << v[right] << '\n';
				break;
			}
			else if (sum < x)  left++;
			else right--;
		}

		if (!chk) cout << "danger" << '\n';
	}
}