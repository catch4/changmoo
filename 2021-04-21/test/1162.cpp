#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
#define ll long long
#define INF 987654321

struct Edge {
    int from, to;
    ll w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

int n,
    m, k;  // 노드10000 간선50000, 비용0인 도로20
ll dist[10001][21];
vector<vector<ll>> dist(10001, vector<ll>(21, INF));
vector<pair<int, int>> graph[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int from, to, w;
        graph[from].push_back({to, w});
        graph[to].push_back({from, w});
    }

    priority_queue<Edge> pq;
    pq.push({0, 1});

    return 0;
}
