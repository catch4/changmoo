#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

bool ans = false;

// T에서 거꾸로 연산해서 S를 만드는게 더 편하다
// 1. 문자열 뒤에 A를 삭제한다
// 2. 문자열 뒤에 B를 삭제하고 뒤집는다
void solve(string s, string t, int n) {
    if (!t.compare(s)) {
        ans = true;
        return;
    }
    if (n == 0) return;

    string t1 = t.substr(0, t.length() - 1);
    if (t.back() == 'B') {
        reverse(t1.begin(), t1.end());
    }
    solve(s, t1, n - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s, t;
    cin >> s >> t;

    int n = t.length() - s.length();
    solve(s, t, n);

    cout << ans;
    return 0;
}
