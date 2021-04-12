#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define INF 987654321

int r, c, n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> c;
    vector<vector<char>> a(r, vector<char>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; ++j) {
            cin >> a[i][j];
        }
    }
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    

    return 0;
}
