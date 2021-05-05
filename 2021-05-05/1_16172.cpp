#include <cctype>
#include <iostream>
#include <string>
using namespace std;

// 조건이 널널해서 kmp O(M+N) 를 안써도 통과됬음 O(NM)
string s, k, s2;  // 200000, 200000이하, 숫자제거된s
bool ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> s >> k;
    for (const char& ch : s) {
        if (!isdigit(ch)) s2.push_back(ch);
    }

    for (int i = 0, j = k.length(); i < s2.length() - k.length() + 1; ++i, ++j) {
        if (s2.substr(i, j) == k) {
            ans = true;
            break;
        }
    }

    cout << ans;
    return 0;
}
