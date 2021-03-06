#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 도착지가 가까운 순으로 배송정보를 정렬하고
// 트럭이 지나가는 마을마다 트럭이 상자를 실을 수 있는 최대치를 모두 더한다
// 경로상에서 트럭이 실을 수 있는 최대치는 (최대용량 - 이미 싣고 있는 박스) 이다

int n, capa, m;  // 마을수2000, 용량10000, 박스정보1000
struct Info {
    int from, to, box;
    bool operator<(const Info& other) const {
        return to < other.to;  // 도착지 오름차순 정렬
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> capa >> m;
    vector<Info> info(m + 1);
    vector<int> truck(n + 1, 0);

    for (int i = 1; i <= m; ++i) {
        int from, to, box;
        cin >> from >> to >> box;
        info[i] = {from, to, box};
    }
    sort(info.begin(), info.end());

    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        auto& [from, to, box] = info[i];
        int maxload = *max_element(truck.begin() + from, truck.begin() + to + 1);
        int rest = min(box, capa - maxload);  // 싣을 수 있는 여유공간은 최대용량-싣고있는 용량
        for (int j = from; j < to; ++j) {
            truck[j] += rest;
        }
        ans += rest;
    }

    cout << ans;
    return 0;
}
