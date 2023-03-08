#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unordered_map<int, int> ump;
	
	int N;
	cin >> N;

	vector<int> v;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		ump[a]++;
	}

	for (auto i : ump) v.push_back(i.first);

	sort(v.begin(), v.end());
	
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < ump[v[i]]; j++) {
			cout << v[i] << '\n';
		}
	}
}
 