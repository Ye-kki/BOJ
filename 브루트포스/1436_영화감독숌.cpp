#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	vector<int> v;

	cin >> N;
	for (int i = 666; i < 3000000; i++) {
		string s = to_string(i);
		if (s.find("666") != string::npos) {
			v.push_back(stoi(s));
			N--;
		}
		
		if (!N) {
			cout << stoi(s);
			return 0;
		}
	}
}