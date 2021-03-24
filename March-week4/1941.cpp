#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

// 조건 1. 7명 중 S가 4명이상
// 조건 2. 가로세로 인접

const int dx[4] = {0, 1, 0, -1};  // 행
const int dy[4] = {1, 0, -1, 0};  // 열

vector<vector<int>> visit(5, vector<int>(5));

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<string> table(5);
    for (int i = 0; i < 5; ++i) {
        cin >> table[i];
    }

    vector<int> bit(18, 0);
    for (int i = 0; i < 7; ++i) {
        bit.push_back(1);
    }

    int ans = 0;
    int startx, starty;
    do {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                visit[i][j] = -1;
            }
        }  // 초기화

        int countS = 0;
        for (int i = 0; i < 25; ++i) {
            if (bit[i] == 1) {
                int x = i / 5;
                int y = i % 5;
                visit[x][y] = 0;
                if (table[x][y] == 'S') {
                    countS++;
                }
                startx = x;
                starty = y;
            }
        }  // 방문할 학생자리 셋팅

        if (countS < 4) continue;  // 조건1 충족

        // 탐색
        queue<pair<int, int>> q;
        q.push({startx, starty});
        visit[startx][starty] = 1;

        int countLen = 1;
        while (!q.empty()) {
            const auto& [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (0 > nx || nx >= 5 || 0 > ny || ny >= 5) continue;
                if (visit[nx][ny]) continue;

                visit[nx][ny] = 1;
                q.push({nx, ny});
                countLen++;
            }
        }

        if (countLen == 7) {
            ans++;
        }
    } while (next_permutation(bit.begin(), bit.end()));

    cout << ans;
    return 0;
}
