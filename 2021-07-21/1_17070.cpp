#include <iostream>
#include <vector>
using namespace std;

int n;
int board[17][17];
int dp[17][17][3];  // k: 가로0,세로1,대각선2 경우의 수

bool valid(int r, int c) {
    if (1 <= r && 1 <= c && r <= n && c <= n && board[r][c] == 0) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // (1,1), (1,2)은 항상 빈칸
    // (0,0) to (n-1,n-1) 가는 방법의 수
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> board[i][j];
        }
    }

    dp[1][2][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (valid(i, j - 1) && valid(i, j))  // 가로
                dp[i][j][0] += dp[i][j - 1][0] + dp[i][j - 1][2];
            if (valid(i - 1, j) && valid(i, j))  // 세로
                dp[i][j][1] += dp[i - 1][j][1] + dp[i - 1][j][2];
            if (valid(i - 1, j - 1) && valid(i - 1, j) && valid(i, j - 1) && valid(i, j))  // 대각선
                dp[i][j][2] += dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
        }
    }

    cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
    return 0;
}
