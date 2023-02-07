#include <iostream>
#include <set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int nA, nB;
	set<int> sA;
	cin >> nA >> nB;

	for (int i = 0; i < nA; i++) {
		int a;
		cin >> a;
		sA.insert(a);
	}
	for (int i = 0; i < nB; i++) {
		int b;
		cin >> b;
		if (sA.find(b) != sA.end()) sA.erase(b);
	}
	
	if (sA.size()) {
		cout << sA.size() << '\n';
		for (auto i : sA) cout << i << ' ';
	}
	else cout << 0;
	
}