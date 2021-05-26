#include <iostream>
#include <vector>
using namespace std;

int n;
int parent[300001];

int find(int u) {
    if (u == parent[u])
        return u;
    else {
        int v = find(parent[u]);
        parent[u] = v;
        return v;
    }
}

void unionFind(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v)
        parent[v] = u;
    else
        parent[u] = v;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    for (int i = 0; i < n - 2; ++i) {
        int u, v;
        cin >> u >> v;
        unionFind(u, v);
    }

    for (int i = 1; i < n; ++i) {
        if (find(i) != find(i + 1)) {
            cout << i << ' ' << i + 1;
            break;
        }
    }

    return 0;
}
