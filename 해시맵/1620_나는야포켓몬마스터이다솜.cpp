#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;

	unordered_map<string, int> name;
	unordered_map<string, string> num;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		name.insert({ s,i });
		num.insert({ to_string(i),s });
	}

	for (int i = 1; i <= M; i++) {
		string s;
		cin >> s;
		if (name.find(s) != name.end()) cout << name[s] << '\n';
		if (num.find(s) != num.end()) cout << num[s] << '\n';
	}
}