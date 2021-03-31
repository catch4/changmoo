#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 987654321
#define pii pair<int, int>

struct Edge {
    int to, weight;
};

int n, p, k;  // 노드, 간선, 무료케이블갯수
vector<Edge> a[1001];
vector<int> dist(1001, INF);

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

    dist[1] = 0;  // 시작
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({dist[1], 0});

    return 0;
}
