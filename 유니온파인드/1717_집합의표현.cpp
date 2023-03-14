#include <iostream>
#include <string.h>

using namespace std;

int parent[1000002]; // 위 그림에서 배열에 해당하는 것
int n, m;

int Find(int x) {
	if (parent[x] == x) // 배열 인덱스와 값이 같다면 해당 값 리턴
		return x;
	return parent[x] = Find(parent[x]); // 배열의 값을 인덱스로 갖는 값 리턴
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y); // 각각 find연산을 통해 루트 노드를 가짐
	if (x == y) return; // x와 y가 같다면 이미 연결되어있는 것
	parent[y] = x; // 배열의 y인덱스에 x값을 저장
}

bool isUnion(int x, int y) { // 두 노드가 연결되어있는지 판별하는 함수
	x = Find(x);
	y = Find(y);
	if (x == y) return true;
	return false;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i <= n; i++) parent[i] = i;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (!a) Union(b, c);
		else {//부모 찾기
			if (isUnion(b, c)) cout << "YES" << '\n';
			else cout << "NO" << '\n';
		}
	}
}