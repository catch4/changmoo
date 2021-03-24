#include <algorithm>
#include <bitset>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 987654321

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    vector<vector<int>> d(n, vector<int>(n, INF));
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; i < n; ++j) {
        }
    }

    cin >> q;

    return 0;
}
