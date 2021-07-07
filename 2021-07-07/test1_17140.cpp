#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#define pii pair<int, int>
using namespace std;

int r, c, k;
int a[100][100];

int solve() {
    int time = 0;
    int row = 3, col = 3;
    while (time <= 100) {
        if (a[r][c] == k) return time;
        time++;

        if (row >= col) {
            for (int i = 1; i <= row; ++i) {
                priority_queue<pii> pq;
                unordered_map<int, int> umap;

                for (int j = 1; j <= col; ++j) {
                    if (a[i][j] != 0) {
                        ++umap[a[i][j]];
                        a[i][j] = 0;
                    }
                }

                for (int j = 1; j <= 100; ++j) {           // col 인덱스
                    if (umap[j]) pq.push({-umap[j], -j});  // {횟수, 숫자}
                }
                col = max(col, (int)pq.size() * 2);

                for (int j = 1; j <= pq.size() * 2; j += 2) {
                    const auto& [times, num] = pq.top();
                    a[i][j] = -num;
                    a[i][j + 1] = -times;
                    pq.pop();
                }
            }
        } else {
            for (int i = 1; i <= col; ++i) {
                priority_queue<pii> pq;
                unordered_map<int, int> umap;

                for (int j = 1; j <= row; ++j) {
                    if (a[j][i] != 0) {
                        ++umap[a[j][i]];
                        a[j][i] = 0;
                    }
                }

                for (int j = 1; j <= 100; ++j) {           // col 인덱스
                    if (umap[j]) pq.push({-umap[j], -j});  // {횟수, 숫자}
                }
                row = max(row, (int)pq.size() * 2);

                for (int j = 1; j <= pq.size() * 2; j += 2) {
                    const auto& [times, num] = pq.top();
                    a[j][i] = -num;
                    a[j + 1][i] = -times;
                    pq.pop();
                }
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> c >> k;
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            cin >> a[i][j];
        }
    }

    cout << solve();
    return 0;
}

// a[r][c] = k 이기 위한 연산의 최소시간
// 100초 지나면 -1 출력