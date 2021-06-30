#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

struct Block {
    int base, h, num;  // 밑면, 높이, 무게, 벽돌번호
};

int n;
vector<Block> v;  // 밑면, 높이, 무게

// 오름차순으로 정렬, 무게1 < 무게2, 밑면1 < 밑면2
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        v.push_back({x, z, i + 1});
    }

    return 0;
}
