#include <iostream>
using namespace std;
#define ll long long
#define INF 987654321

long long dp[11][101][101][101];
long long combi[11][11];
// d[n][a][b][c] = 높이n에서 남은 장난감 a,b,c개 배치하는 경우의 수
// combi[n][n] = 경우의 수 조합
void calc_combi(int n, int div, int color) {
    if (combi[n][n / 2] != 0) return;
    long long combination = 1;
    for (int i = 1; i <= n; ++i) {
        combination *= i;
    }

    for (int i = 0; i < color; ++i) {
        for (int j = 1; j <= div; ++j) {
            combination /= j;
        }
    }

    combi[n][div] = combination;
}

int solve(int n, int a, int b, int c) {
    if (n == 0) return 1;
    if (a < 0 || b < 0 || c < 0) return 0;
    if (dp[n][a][b][c] != 0) return dp[n][a][b][c];  // base case

    dp[n][a][b][c] += solve(n - 1, a - n, b, c);
    dp[n][a][b][c] += solve(n - 1, a, b - n, c);
    dp[n][a][b][c] += solve(n - 1, a, b, c - n);

    if (n % 2 == 0) {  // 2의 배수 h
        calc_combi(n, n / 2, 3);
        long long combination = combi[n][n / 2];
        dp[n][a][b][c] += combination * solve(n - 1, a - n / 2, b - n / 2, c);
        dp[n][a][b][c] += combination * solve(n - 1, a - n / 2, b, c - n / 2);
        dp[n][a][b][c] += combination * solve(n - 1, a, b - n / 2, c - n / 2);
    }

    if (n % 3 == 0) {  // 3의 배수 h
        calc_combi(n, n / 3, 3);
        long long combination = combi[n][n / 3];
        dp[n][a][b][c] = combination * solve(n - 1, a - n / 3, b - n / 3, c - n / 3);
    }

    return dp[n][a][b][c];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, a, b, c;  // 10, 0~100
    cin >> n >> a >> b >> c;

    cout << solve(n, a, b, c);
    return 0;
}
