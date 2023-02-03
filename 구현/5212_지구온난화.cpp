#include <iostream>
#include <algorithm>

using namespace std;

int R, C;
char map[13][13];
int goY[4] = { 0,0,1,-1 }, goX[4] = { 1,-1,0,0 };
int minY = 987654321, minX = 987654321;
int maxY = 0, maxX = 0;

bool is_in_board(int y, int x) {
    if (y < 0 || x < 0 || y >= R || x >= C) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) cin >> map[i][j];
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j] == 'X') {
                int cnt = 0;
                for (int k = 0; k < 4; k++) {
                    int nextY = i + goY[k], nextX = j + goX[k];
                    if (!is_in_board(nextY, nextX)) {
                        cnt++;
                        continue;
                    }
                    if (map[nextY][nextX] == '.') cnt++;
                }
                if (cnt >= 3) map[i][j] = 'a';
            }
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j] == 'a') map[i][j] = '.';
            if (map[i][j] == 'X') {
                if (i <= minY) minY = i;
                if (j <= minX) minX = j;
                if (i >= maxY) maxY = i;
                if (j >= maxX) maxX = j;
            }
        }
    }

    for (int i = minY; i <= maxY; i++) {
        for (int j = minX; j <= maxX; j++) cout << map[i][j];
        cout << '\n';
    }
}