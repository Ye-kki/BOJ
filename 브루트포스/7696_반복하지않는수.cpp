#include <iostream>
#include <vector>
#include <string.h>
#include <string>

using namespace std;

int n, idx = 1;
int visited[10] = { 0, };
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	while (n) {
		while (v.size() < n) {
			memset(visited, 0, sizeof(visited));
			int tmp = idx;
			v.push_back(idx);
			while (tmp) {
				if (visited[tmp % 10]) {
					v.pop_back();
					break;
				}
				visited[tmp % 10] = 1;
				tmp /= 10;
			}
			idx++;
		}
		cout << v[n - 1] << '\n';
		cin >> n;
	}
}