// 슬라이딩 윈도우
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> s;
    int bNum = 0, ans;
    for (char ch : s) {
        if (ch == 'b') bNum++;
    }
    s += s;
    ans = bNum;  // 4

    queue<int> q;
    for (int i = 0; i < s.length(); ++i) {
        if (!q.empty() && i - q.front() >= bNum) q.pop();  // b인 인덱스가 있고 현재 인덱스와 b인덱스의 거리가 b갯수보다 많으면 pop
        if (s[i] == 'b') q.push(i);                        // 2,3,7,10

        ans = min(ans, bNum - (int)q.size());
    }
    cout << ans;
    return 0;
}
