#include <iostream>
#include <vector>
#define INF 987654321
#define pii pair<int, int>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        bool cycle = false;
        int n, m, w;
        int u, v, weight;
        cin >> n >> m >> w;
        vector<pii> edge[n + 1];  // {v, weight}
        vector<int> dist(n + 1, INF);

        for (int i = 0; i < m; i++) {
            cin >> u >> v >> weight;
            edge[u].push_back({v, weight});
            edge[v].push_back({u, weight});
        }
        for (int i = 0; i < w; i++) {
            cin >> u >> v >> weight;
            edge[u].push_back({v, -weight});
        }

        dist[0] = dist[1] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (auto& e : edge[j]) {
                    const auto& [next, cost] = e;
                    if (dist[j] != INF && dist[j] + cost < dist[next]) {
                        dist[next] = dist[j] + cost;
                        if (i == n) cycle = true;
                    }
                }
            }
        }
        if (cycle)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
