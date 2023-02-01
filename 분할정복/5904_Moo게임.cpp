#include <iostream>

using namespace std;

int N;
char S[3] = { 'm', 'o','o' };

void partition(int n, int k, int len) {
    int new_len = len * 2 + k + 3;

    if (n <= 3) {
        cout << S[n - 1];
        return;
    }
    if (new_len < n) partition(n, k + 1, new_len); //다음 길이를 넘어서면 길이 늘려서 재귀
    else { //현재 길이 안에 들어오면 
        if (n > len && n <= len + k + 3) { //S(K-1) 사이인 경우
            if (n - len != 1) cout << 'o'; // 첫번째만 아니면 o 출력
            else cout << 'm'; // 첫번째면 m 출력
            return;
        }
        else partition(n - (len + k + 3), 1, 3); //두번째 S(K-1) 인 경우 가운데 부분을 빼고 다시 처음부터 재귀
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
    partition(N, 1, 3);
}