#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define pii pair<int, int>

using namespace std;

int n, m, l;  // 현재휴게소100, 추가휴게소100, 고속도로길이1000

bool check(int range, vector<int>& v) {
    // int cnt = 0;
    // for (int i = 0; i < v.size() - 1; ++i) {
    //     int nRange = v[i + 1] - v[i];
    //     if (nRange / range > 0) {
    //         if (nRange % range == 0)
    //             cnt += nRange / range - 1;
    //         else
    //             cnt += nRange / range;
    //     }
    // }
    // return cnt <= m ? true : false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> l;  // 6, 7, 800
    vector<int> v = {0, l};
    for (int i = 0; i < n; ++i) {
        int location;
        cin >> location;
        v.push_back(location);
    }
    sort(v.begin(), v.end());
    int start = 0, end = l, mid;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (check(mid, v)) {
            end = mid - 1;
        } else
            start = mid + 1;
    }

    cout << mid;
    return 0;
}
