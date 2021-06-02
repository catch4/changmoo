#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int from, to, cost;
    bool operator<(const Edge &other) const {
        return cost < other.cost;
    }
};

int n, m;
vector<int> parent(1001);
vector<Edge> edgeList;

int Find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = Find(parent[u]);
}

void Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    parent[u] = v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        parent[i] = i;
    }
    for (int i = 0; i <= n; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        edgeList.push_back({u, v, 1 - c});
    }
    sort(edgeList.begin(), edgeList.end());

    int min = 0, max = 0;
    for (auto edge : edgeList) {  // minimum spanning
        int u = edge.from;
        int v = edge.to;
        int cost = edge.cost;
        if (Find(u) != Find(v)) {
            Union(u, v);
            min += edge.cost;
        }
    }

    for (int i = 0; i <= m; i++) {
        parent[i] = i;
    }
    for (int i = n + 1; i >= 0; --i) {  // maximum spanning
        int u = edgeList[i].from;
        int v = edgeList[i].to;
        int cost = edgeList[i].cost;
        if (Find(u) != Find(v)) {
            Union(u, v);
            max += cost;
        }
    }

    cout << max * max - min * min;

    return 0;
}
