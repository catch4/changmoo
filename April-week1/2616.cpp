#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int n, m;  // 객차의 수 50000, 최대로 끌 수있는 객차수 n/3미만
vector<int> v;

int solve() {
    int ret = 0;
    if (n % 3 == 1) {  // 남는 객차가 1개인 경우
        // 양 끝 중 하나인 경우
        // 안 쪽인 경우
    }

    else if (n % 3 == 2) {
        // 양 끝인 경우
        // 하나만 끝이고 하나는 안쪽인 경우
        // 둘다 안쪽인 경우
    }

    else {
        for (int i : v) {
            ret += i;
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    vector<int> v(n);  // 손님의 수 100
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    cin >> m;

    cout << solve();

    return 0;
}
