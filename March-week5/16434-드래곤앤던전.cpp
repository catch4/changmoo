#include <climits>
#include <iostream>
#include <vector>
using namespace std;

struct Room {
    int t, a, h;
};

struct Man {
    long long maxHP, currHP, atk;
    Man(int _x, int _y, int _z) : maxHP(_x), currHP(_y), atk(_z) {}
};

int n, atk;  // 방개수123456, 초기공격력1000000
vector<Room> v;

bool solve(int x) {
    Man man = Man(x, x, atk);
    vector<Room> v2 = v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> atk;
    for (int i = 0; i < n; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        v.push_back({x, y, z});
    }

    long long start = 0;
    long long end = LLONG_MAX;
    long long ans = -1;

    while (start <= end) {
        int mid = (start + end) / 2;
        if (solve(mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    cout << ans;
    return 0;
}
