#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, B ,C;
	cin >> N;

	long long cnt = N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];

	cin >> B >> C;

	sort(v.begin(), v.end());

	for (int i = N - 1; i >= 0; i--) {
		if ((v[i] - B) <= 0) {
			//총감독관만 
			break;
		}
		if ((v[i] - B) % C != 0) {
			cnt += ((v[i] - B) / C) + 1;
		}
		else cnt += (v[i] - B) / C;
	}
	cout << cnt;
}