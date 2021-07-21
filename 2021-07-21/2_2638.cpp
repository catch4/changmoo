#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

int n, m, ans;
int board[100][100];  // 치즈1 빈칸0
int contact[100][100];
bool check[100][100];

void dfs(int r, int c) {
    if (board[r][c] || check[r][c]) return;

    check[r][c] = true;
    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr < 0 || nc < 0 || nr >= n || nc >= m || check[nr][nc]) continue;
        if (board[nr][nc] > 0)
            ++contact[nr][nc];
        else
            dfs(nr, nc);
    }
}

bool melt() {
    bool cheese = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (contact[i][j] >= 2) {
                board[i][j] = 0;
                cheese = true;
            }
        }
    }

    return cheese;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    while (1) {
        memset(check, false, sizeof(check));
        memset(contact, 0, sizeof(contact));
        dfs(0, 0);  // 공기
        bool cheese = melt();
        if (!cheese) break;
        ++ans;
    }

    cout << ans;
    return 0;
}
