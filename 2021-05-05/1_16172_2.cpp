#include <iostream>
#include <string>

using namespace std;

int pi[200001];   // prefix suffix 일치하는 부분문자열 길이
string s, s2, k;  // s2에서 패턴k를 검색한다 kmp

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> s >> k;
    for (const char& ch : s)
        if (!isdigit(ch)) s2.push_back(ch);

    for (int i = 1, j = 0; i < k.length(); ++i) {
        while (j > 0 && k[i] != k[j]) {
            j = pi[j - 1];
        }
        if (k[i] == k[j]) {
            pi[i] = j + 1;
            j++;
        }
    }  // s2의 index 마다 prefix == suffix인 최대 부분문자열 길이를 구한다.

    for (int i = 0, j = 0; i < s2.length(); ++i) {
        while (j > 0 & s2[i] != k[j]) j = pi[j - 1];  // 같을 때까지 비교
        if (s2[i] == k[j]) {
            if (j == k.length() - 1) {
                cout << 1;
                return 0;
            } else
                ++j;
        }
    }

    cout << 0;
    return 0;
}
