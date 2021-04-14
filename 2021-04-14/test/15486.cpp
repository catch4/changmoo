#include <cmath>
#include <iostream>
using namespace std;

const int MAX = 1500000;
int n;  // 1500000
int t[MAX + 1];
int p[MAX + 1];
int dp[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> t[i] >> p[i];
    }

    for (int i = n; i >= 1; --i) {  // 거꾸로 세어나감
        if (i + t[i] > n + 1) {     // 강의기간이 근무기간을 넘어가면 패스
            dp[i] = dp[i + 1];
        } else {  // dp[i] = 내가 진행가능한 강의 페이의 최대값
            dp[i] = max(dp[i + 1], p[i] + dp[i + t[i]]);
            // 강의 안 받은 날 다음날 돈 vs 오늘 + 강의 받은 돈
        }
    }

    cout << dp[1];
    return 0;
}
