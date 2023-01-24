#include <iostream>
#include <string>
#include <set>

using namespace std;

int N;
set<int> s;
set<string> ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> N) {
		ans.clear();
		for (int i = 0; i < N; i++) {
			string s1, s2;
			s.clear();
			cin >> s1;
			for (int j = 0; j < s1.size(); j++) s.insert(s1[j]);
			for (auto i : s) s2 += i;
			ans.insert(s2);
		}
		cout << ans.size() << '\n';
	}
}