#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define pii pair<int, int>
using namespace std;

int n, ans;
vector<pii> v;
priority_queue<int> pq;  // 진행중인 강의

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        int num, s, e;
        cin >> num >> s >> e;
        v[i] = {s, e};
    }
    sort(v.begin(), v.end());  // 시작,끝이 빠른 순으로

    for (int i = 0; i < n; ++i) {
        while (!pq.empty() && -pq.top() <= v[i].first) {  // 지금강의 끝나는 시간보다 새 강의 시간이 같거나 빠르면 pop
            pq.pop();
        }
        pq.push(-v[i].second);
        ans = max(ans, (int)pq.size());
    }

    cout << ans;
    return 0;
}
