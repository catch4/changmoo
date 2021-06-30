#include <iostream>
#include <vector>
using namespace std;

int n, m, x;  // 학생수100000, 질문수, 학생인덱스(1~n)
vector<int> g[100001];
int ind[100001];

// max등수, min등수 DAG
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> x;
    for (int i = 1; i <= n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        ind[u]++;
    }

    return 0;
}
