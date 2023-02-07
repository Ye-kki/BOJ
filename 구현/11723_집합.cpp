#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int M;
	bool arr[20] = { 0, };
	cin >> M;

	for (int i = 0; i < M; i++) {
		string s;
		int a;
		cin >> s;
		if (s == "add") {
			cin >> a;
			arr[a - 1] = 1;
		}
		else if (s == "remove") {
			cin >> a;
			arr[a - 1] = 0;
		}
		else if (s == "check") {
			cin >> a;
			cout << arr[a - 1] << '\n';
		}
		else if (s == "toggle") {
			cin >> a;
			arr[a - 1] = !arr[a - 1];
		}
		else if (s == "all") {
			for (int j = 0; j < 20; j++) arr[j] = 1;
		}
		else {
			for (int j = 0; j < 20; j++) arr[j] = 0;
		}
	}
}