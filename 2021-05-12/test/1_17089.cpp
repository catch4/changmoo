#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int n, m, ans = INT_MAX;  // 사람4000 관계4000
vector<int> g[4001];
int adj[4001][4001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= g[i].size(); ++j) {
            for (int k = j + 1; k < g[i].size(); ++k) {
                int c1 = g[i][j];  // 관계1
                int c2 = g[i][k];  // 관계2
                if (adj[c1][c2]) {
                    int amount = g[i].size() + g[j].size() + g[k].size();
                    ans = min(ans, amount - 6);
                }
            }
        }
    }

    if (ans == INT_MAX)
        cout << -1;
    else
        cout << ans;
    return 0;
}
