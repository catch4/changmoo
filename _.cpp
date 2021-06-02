#include <cstring>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

const int dr[9] = {0, 1, 1, 1, 0, -1, -1, -1, 0};
const int dc[9] = {-1, -1, 0, 1, 1, 1, 0, -1, 0};

struct Pos {
    int r, c, time;
};

string map[8];
bool visit[8][8];

// 캐릭터 먼저 이동함
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i < 8; ++i) {
        cin >> map[i];
    }

    queue<Pos> q;
    q.push({7, 0, 0});  // map[7][0] 시작
    visit[7][0] = true;

    while (!q.empty()) {
        memset(visit, false, sizeof(visit));

        for (int i = 0; i < q.size(); ++i) {
            Pos now = q.front();
            q.pop();

            if ((now.r == 0 && now.c == 7) || now.time == 8) {  // map[0][7]
                cout << 1;
                return 0;
            }

            for (int i = 0; i < 9; ++i) {
                Pos npos;
                npos.r = now.r + dr[i];
                npos.c = now.c + dc[i];
                npos.time = now.time + 1;
                if (npos.r < 0 || npos.c < 0 || npos.r >= 8 || npos.c >= 8) continue;
                if (visit[npos.r][npos.c] || map[npos.r][npos.c] == '#') continue;

                visit[npos.r][npos.c] = true;
                q.push(npos);
            }
        }
        // 벽이동
    }

    cout << 0;
    return 0;
}
