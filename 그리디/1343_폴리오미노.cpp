#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	vector<int> v;
	cin >> s;

	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'X') {
			int cnt = 0;
			for (int j = i; j < s.size(); j++) {
				
				if (s[j] == '.' || j == s.size()-1) {
					if (s[j] == 'X' && j == s.size() - 1) cnt++;
					string ans;
					if (cnt == 2) ans.append("BB");
					else if (cnt % 4 == 0) {
						for (int j = 0; j < cnt; j++) ans.append("A");
					}
					else if (cnt % 4 == 2) {
						for (int j = 0; j < cnt - 2; j++) ans.append("A");
						ans.append("BB");
					}
					else {
						cout << -1;
						return 0;
					}
					s.replace(i, cnt, ans);

					i = j;
					break;
				}
				cnt++;
			}
		}
	}
	cout << s;
}