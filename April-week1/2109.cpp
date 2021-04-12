#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, ans;
vector<pair<int, int>> a;
priority_queue<int> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int pay, day;
        cin >> pay >> day;
        a.push_back({day, -pay});
    }
    sort(a.begin(), a.end());  // day 오름차순, pay 내림차순

    for (int i = 0; i < n; ++i) {
        ans -= a[i].second;
        pq.push(a[i].second);

        if (a[i].first >= pq.size()) continue;  // pq.size()는 현재 소요기간
        ans += pq.top();
        pq.pop();
    }

    cout << ans;
    return 0;
}
