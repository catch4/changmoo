#include <cstring>
#include <iostream>
using namespace std;

const int dr[4] = {-1, 1, 0, 0};  // 상하좌우
const int dc[4] = {0, 0, -1, 1};

struct Shark {
    int r, c, dir;
    int priority[4][4];  // 상하좌우별 우선순위
};

int n, m, k, ans = -1;
int board[20][20][3];  // 0: id, 1: 냄새id, 2: 냄새남은시간
Shark shark[401];

void solve() {
    int time = 0;
    int alive = m;  // 1 남으면 return time;

    while (time <= 1000) {
        ++time;

        // 1. 냄새 감소
        int nBoard[20][20][3];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                nBoard[i][j][0] = board[i][j][0];
                nBoard[i][j][2] = board[i][j][2];
                if (nBoard[i][j][2] > 0) --nBoard[i][j][2];
                if (nBoard[i][j][2] > 0) nBoard[i][j][1] = board[i][j][1];
            }
        }

        for (int i = 1; i <= m; ++i) {
            int r = shark[i].r;
            int c = shark[i].c;
            int dir = shark[i].dir;
            if (r == -1) continue;

            bool moved = false;
            for (int d = 0; d < 4; ++d) {
                int ndir = shark[i].priority[dir][d];
                int nr = r + dr[ndir];
                int nc = c + dc[ndir];
                if (0 > nr || 0 > nc || n <= nr || n <= nc) continue;
                if (board[nr][nc][2] != 0) continue;  // 냄새 있으면 패스

                moved = true;
                if (nBoard[nr][nc][0] == 0) {  // 상어 안 겹치면
                    nBoard[nr][nc][0] = i;
                    nBoard[nr][nc][1] = i;
                    nBoard[nr][nc][2] = k;
                    shark[i].r = nr;
                    shark[i].c = nc;
                    shark[i].dir = ndir;
                    nBoard[r][c][0] = 0;
                } else {
                    --alive;
                    shark[i].r = -1;
                    nBoard[r][c][0] = 0;
                }
                break;
            }

            if (!moved) {
                for (int d = 0; d < 4; ++d) {
                    int ndir = shark[i].priority[dir][d];
                    int nr = r + dr[ndir];
                    int nc = c + dc[ndir];
                    if (0 > nr || 0 > nc || n <= nr || n <= nc) continue;
                    if (board[nr][nc][2] != 0 && board[nr][nc][1] != i) continue;

                    if (nBoard[nr][nc][0] == 0) {  // 상어 안 겹치면
                        nBoard[nr][nc][0] = i;
                        nBoard[nr][nc][1] = i;
                        nBoard[nr][nc][2] = k;
                        shark[i].r = nr;
                        shark[i].c = nc;
                        shark[i].dir = ndir;
                        nBoard[r][c][0] = 0;
                    } else {
                        --alive;
                        nBoard[r][c][0] = 0;
                        shark[i].r = -1;
                    }
                    break;
                }
            }
        }

        if (alive == 1) break;

        memcpy(board, nBoard, sizeof(board));
    }

    if (time <= 1000) ans = time;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j][0];  // 1~m
            if (board[i][j][0] != 0) {
                int id = board[i][j][0];
                board[i][j][1] = board[i][j][0];
                board[i][j][2] = k;
                shark[id].r = i;
                shark[id].c = j;
            }
        }
    }

    for (int i = 1; i <= m; ++i) {
        cin >> shark[i].dir;  // 1,2,3,4
        --shark[i].dir;
    }

    for (int i = 1; i <= m; ++i) {
        for (int d = 0; d < 4; ++d) {  // 0,1,2,3
            cin >> shark[i].priority[d][0] >> shark[i].priority[d][1] >> shark[i].priority[d][2] >> shark[i].priority[d][3];
            --shark[i].priority[d][0];
            --shark[i].priority[d][1];
            --shark[i].priority[d][2];
            --shark[i].priority[d][3];
        }
    }

    solve();
    cout << ans;
    return 0;
}
