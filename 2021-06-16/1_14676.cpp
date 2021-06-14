#include <iostream>
#include <vector>
#define MAX 100000
using namespace std;

int n, m, k;  // 100000
vector<int> graph[MAX + 1];
int ind[MAX + 1];
int techtree[MAX + 1];

bool isPossible() {
    for (int i = 0; i < k; ++i) {
        int action, u;  // 건설or파괴, 건물번호
        cin >> action >> u;
        if (action == 1) {             // 건설
            if (ind[u]) return false;  // 이전 테크트리 있으면 false
            techtree[u]++;
            if (techtree[u] == 1) {  // 1이상이면 선행건물로부터의 in-degree 제거
                for (int v : graph[u]) {
                    ind[v]--;
                }
            }
        } else {                             // 파괴
            if (!techtree[u]) return false;  // 테크건물 없으면 false
            techtree[u]--;
            if (techtree[u] == 0) {
                for (int v : graph[u]) {
                    ind[v]++;
                }
            }
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        ind[v]++;
    }

    if (isPossible())
        cout << "King-God-Emperor";
    else
        cout << "Lier!";

    return 0;
}
