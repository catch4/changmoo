#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m, ans;  // 책개수, 한번에 들 책 갯수
vector<int> v, w;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        a >= 0 ? v.push_back(a) : w.push_back(-a);
    }
    sort(v.begin(), v.end());
    sort(w.begin(), w.end());

    for (int i = v.size() - 1; i >= 0; i -= m) {  // + 방향
        ans += v[i] * 2;
    }
    for (int i = w.size() - 1; i >= 0; i -= m) {  // - 방향
        ans += w[i] * 2;
    }

    int vLast, wLast;
    v.empty() ? vLast = 0 : vLast = v.back();
    w.empty() ? wLast = 0 : wLast = w.back();
    ans -= max(vLast, wLast);

    cout << ans;
    return 0;
}
