#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define INF 987654321
#define pii pair<int, int>

struct Edge {
    int to, weight;
};

int n, p, k, ans = -1;  // 노드1000, 엣지10000, 무료케이블1000
vector<Edge> a[1001];

bool solve(int money) {  // 다익스트라
    vector<int> dist(1001, INF);
    // vector<bool> check(1001);
    priority_queue<pii, vector<pii>, greater<>> pq;
    dist[1] = 0;            // 시작점
    pq.push({dist[1], 1});  //

    while (!pq.empty()) {
        const auto& [d, x] = pq.top();  // 도달가격passed, 노드인덱스here
        pq.pop();

        // if (dist[x] > d) continue;

        // for (int i = 0; i < a[x].size(); ++i) {
        //     int y = a[x][i].to;
        //     int weight = d + (a[x][i].weight > money);

        //     if (dist[y] > weight) {
        //         dist[y] = weight;
        //         pq.push({dist[y], y});
        //     }
        // }
    }

    return dist[n] <= k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> p >> k;
    for (int i = 0; i < p; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        a[x].push_back({y, w});
        a[y].push_back({x, w});
    }

    int left = 0, right = 1e6;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (solve(mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans;
    return 0;
}
