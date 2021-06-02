#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 987654321
#define pii pair<int, int>

// 한 골목에서 내야되는 최대요금을 최소화
int n, m, s, e, money;  // 교차로10,골목,시작,도착,가진돈

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> s >> e >> money;
    vector<pii> a[m + 1];
    vector<int> dist(n + 1, INF);
    vector<bool> visit(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back({v, w});
        a[v].push_back({u, w});
    }

    dist[s] = 0;

    return 0;
}
