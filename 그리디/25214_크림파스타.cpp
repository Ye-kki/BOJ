#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	int maxN, minN;
	vector<int> v;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	maxN = 0;
	minN = v[0];
	for (int i = 0; i < N; i++) {
		minN = min(v[i], minN);
		maxN = max(v[i] - minN, maxN);
		cout << maxN << ' ';
	}
}