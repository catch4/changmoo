#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
using namespace std;

int n;
int matrix[501][2];
int dp[501][501];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> matrix[i][0] >> matrix[i][1];
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= n - i; j++) {
            for (int k = j + 1; k < j + i; k++) {
                int result = dp[j][k] + dp[k][j + i] + matrix[j][0] * matrix[k][0] * matrix[j + i - 1][1];
                dp[j][j + i] = min(INT_MAX, result);
            }
        }
    }

    cout << dp[0][n];
    return 0;
}
