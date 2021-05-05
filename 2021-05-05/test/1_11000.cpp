#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define pii pair<int, int>

using namespace std;

int n, ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    vector<pii> range(n);
    for (int i = 0; i < n; ++i) {
        int from, to;
        cin >> from >> to;
        range[i] = {from, to};
    }
    sort(range.begin(), range.end());  // 강의 빨리 끝나는 순

    priority_queue<int, vector<int>, greater<int>> room;  // 강의 끝나는 시간 오름차순
    room.push(range[0].second);
    for (int i = 1; i < n; ++i) {
        const auto& [from, to] = range[i];
        int now = room.top();  // 제일 빨리 끝나는 강의실

        if (now <= from) room.pop();  // 강의 끝나는 시간 <= 강의 시작 시간이면 그 강의실 이용
        room.push(to);
    }

    cout << room.size();
    return 0;
}
