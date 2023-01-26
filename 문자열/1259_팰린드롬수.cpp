#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	while (s != "0") {
		bool chk = true;
		for (int i = 0; i < s.size() / 2; i++) {
			if (s[i] != s[s.size() - 1 - i]) chk = false;
		}
		if(chk) cout << "yes" << '\n';
		else cout << "no" << '\n';
		cin >> s;
	}
}