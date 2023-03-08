#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	unordered_map<int, int> ump;

	cin >> N;

	vector<int> v;
	vector<int> ans(N);

	for (int i = 0; i < N; i++) {
		cin >> ans[i];
		ump[ans[i]] = 1;
	}

	for (auto i : ump) v.push_back(i.first);

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) ump[v[i]] = i;


	for (int i = 0; i < ans.size(); i++) {
		cout << ump[ans[i]] << ' ';
	}

}
 