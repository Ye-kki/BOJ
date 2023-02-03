#include <iostream>

using namespace std;

int N, R, C;
int ans;

int pow(int a, int b) {
    int tmp = 1;
    while (b--) tmp *= a;
    return tmp;
}

void partition(int y, int x, int n) {

    if (y == R && x == C) {
        cout << ans;
        return;
    }

    if (R >= y && R < y + n && C >= x && C < x + n) {
        partition(y, x, n / 2);
        partition(y, x + n / 2, n / 2);
        partition(y + n / 2, x, n / 2);
        partition(y + n / 2, x + n / 2, n / 2);
    }
    else {
        ans += n * n;
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> R >> C;
    partition(0, 0, pow(2, N));
}