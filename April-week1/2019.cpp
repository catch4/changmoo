#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 987654321

int n;                     // 대학갯수 10000
vector<pair<int, int>> v;  // d제한시간 10000, p원 강연료 10000
priority_queue<int, vector<int>, greater<int>> pq;
// 하루 최대 한 곳에서 강연 가능,
// 빨리 해야되는거 먼저 스케쥴 잡고,

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int p, d;
        cin >> p >> d;
        v.push_back({d, p});  // 제한시간 오름차순 정렬
    }
    sort(v.begin(), v.end());

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        const auto& [d, p] = v[i];

        ans += p;
        pq.push(p);  // 더한 가격 최소힙에 추가
        if (pq.size() > d) {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans;
    return 0;
}
