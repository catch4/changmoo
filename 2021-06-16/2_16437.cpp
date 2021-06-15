#include <iostream>
#include <vector>
#define MAX 123456
using namespace std;

int n;
int parent[MAX + 1];  // 부모노드 기록
int tree[MAX + 1];    // 양 또는 늑대 마리수

int calc(int sheep, int idx) {  // 100, 3 시작
    if (idx == 1) return sheep;

    if (tree[idx] < 0) {  // 늑대인 경우
        if (sheep < -tree[idx]) return 0;
        return calc(sheep + tree[idx], parent[idx]);
    }

    return calc(sheep, parent[idx]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 2; i <= n; ++i) {
        char t;    // w늑대, s양
        int a, p;  // i번째섬에 늑대or양a, i번째섬에서p섬으로다리
        cin >> t >> a >> p;
        parent[i] = p;
        if (t == 'W')
            tree[i] = -a;  // 늑대
        else
            tree[i] = a;  // 양
    }

    long long sum = 0;
    for (int i = 2; i <= n; ++i) {
        if (tree[i] > 0) {  // 양이면 1번섬 까지 이동해서 남은값 더함
            sum += calc(tree[i], parent[i]);
        }
    }

    cout << sum;
    return 0;
}
