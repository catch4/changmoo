#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 987654321

// 5! * 4^5 = 122880 판 5개 배치 * 판 5개 로테이션 4방향
/// 000 -> 444 가는 최단거리 bfs

int dz[] = {0, 0, 0, 0, 1, -1};
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};

int map[5][5][5];
int cpymap[5][5][5];
int d[5][5][5];
int ans = INF;

void rotate(int h) {
    int board[5][5];
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            board[j][4 - i] = cpymap[h][i][j];
        }
    }

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cpymap[h][i][j] = board[i][j];
        }
    }
}

void bfs() {
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    memset(d, -1, sizeof(d));

    while (!q.empty()) {
        const auto& [x, y, z] = q.front();
        q.pop();

        if (x == 4 && y == 4 && z == 4) {
            ans = min(ans, d[x][y][z]);
            return;
        }

        for (int i = 0; i < 5; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || nz < 0 || nz >= 5) continue;
            if (cpymap[nx][ny][nz] && d[nx][ny][nz] == -1) {
                q.push({nx, ny, nz});
                d[nx][ny][nz] = d[x][y][z] + 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            for (int k = 0; k < 5; ++k) {
                cin >> map[i][j][k];
            }
        }
    }

    vector<int> combi(5);
    for (int i = 0; i < 5; ++i) {
        combi[i] = i;
    }

    do {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                for (int k = 0; k < 5; ++k) {
                    cpymap[i][j][k] = map[i][j][k];
                }
            }
        }

        for (int i = 0; i < 4; ++i) {
            rotate(0);
            if (!cpymap[0][0][0]) continue;
            for (int j = 0; j < 4; ++j) {
                rotate(1);
                for (int k = 0; k < 4; ++k) {
                    rotate(2);
                    for (int m = 0; m < 4; ++m) {
                        rotate(3);
                        for (int n = 0; n < 4; ++n) {
                            rotate(4);
                            if (cpymap[4][4][4]) {
                                bfs();
                            }
                        }
                    }
                }
            }
        }
    } while (next_permutation(combi.begin(), combi.end()));

    if (ans == INF) {
        cout << -1;
    } else {
        cout << ans;
    }

    return 0;
}
