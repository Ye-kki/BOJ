#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int n = 1;
	cin >> N;

	while (N != 0) {
		vector<string> v(N);
		set<int> s;

		cin.ignore();

		for (int i = 0; i < N; i++) {
			getline(cin, v[i]);
		}

		for (int i = 0; i < 2 * N - 1; i++) {
			int a;
			char c;
			cin >> a >> c;
			if (s.find(a) != s.end()) s.erase(a);
			else s.insert(a);
		}
		
		for (auto i : s) cout << n << ' ' << v[i - 1] << '\n';

		n++;
		cin >> N;
	}


}