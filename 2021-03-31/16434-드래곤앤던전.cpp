#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
#define ull unsigned long long

struct Room {
    int t, a, h;  //
    // t가 1이면 몬스터 공격력 a, 생명력 h 1,000,000
    // t가 2이면 용사 공격력 a증가, 생명력 h증가
};

int n, atk;  // 방갯수123456,초기공격력1,000,000
vector<Room> room;

bool solve(ull atk, ull maxHP) {
    ull currHP = maxHP;

    for (int i = 0; i < n; ++i) {
        if (room[i].t == 1) {           // 몬스터방인 경우
            ull cnt = room[i].h / atk;  // 공격횟수, 용사 선공

            if (room[i].h % atk > 0) cnt++;         // 막타
            if (currHP <= (cnt - 1) * room[i].a) {  // 트라이 실패
                return false;
            }
            currHP -= (cnt - 1) * room[i].a;          // 공격횟수 * 몬스터 공격력
        } else {                                      // 물약방인 경우
            currHP = min(currHP + room[i].h, maxHP);  // 물약 먹어도 maxHP 이상 못 채움
            atk += room[i].a;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> atk;
    room.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> room[i].t >> room[i].a >> room[i].h;
    }

    ull l = 0, r = ULLONG_MAX, ans = 0;
    while (l <= r) {
        ull maxHP = (l + r) / 2;
        if (solve(atk, maxHP)) {
            r = maxHP - 1;
            ans = maxHP;
        } else {
            l = maxHP + 1;
        }
    }

    cout << ans;
    return 0;
}
