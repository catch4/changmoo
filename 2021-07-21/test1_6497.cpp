#include <algorithm>
#include <iostream>
#include <vector>
#define union _union
using namespace std;

int m, n, ans;
int parent[200001];
vector<pair<int, pair<int, int>>> edges;

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void union(int a, int b) {
    a = find(a);
    b = find(b);
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> m >> n;

    for (int i = 0; i < n; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        edges.push_back({z, {x, y}});
        ans += z;
    }

    for (int i = 1; i <= m; ++i) {
        parent[i] = i;
    }

    sort(edges.begin(), edges.end());

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        int w = edges[i].first;

        if (find(u) != find(v)) {
            union(u, v);
            ans -= w;
        }
    }

    cout << ans;
    return 0;
}