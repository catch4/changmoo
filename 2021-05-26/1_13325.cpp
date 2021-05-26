#include <algorithm>
#include <iostream>

using namespace std;

int n, k, ans;
int a[(1 << 21) + 1];

int calc(int pos) {
    int left = 2 * pos + 1;
    int right = left + 1;
    if (left > n || right > n) return a[pos];

    int lsum = calc(left);
    int rsum = calc(right);

    // 왼쪽길이랑 오른쪽 길이 맞추기
    if (lsum < rsum)
        a[left] += rsum - lsum;
    else if (lsum > rsum)
        a[right] += lsum - rsum;

    return a[pos] + max(lsum, rsum);
}

int main() {
    cin >> k;
    n = (1 << (k + 1)) - 2;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    calc(0);

    for (int i = 1; i <= n; ++i) {
        ans += a[i];
    }

    cout << ans;
    return 0;
}
