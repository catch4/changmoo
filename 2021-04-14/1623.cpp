#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 트리 구현 후, 사장이 참석하는 경우의 순회, 사장이 참석하지 않는 경우의 순회
// 1. 사장이 참석하는 경우
// 2. 사장이 참석하지 않는 경우

const int MAX = 200000;
int n;  // 직원수 200000
int attend, notAttend;

vector<int> score(MAX + 1);
vector<int> tree[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;  // 직원수

    for (int i = 1; i <= n; ++i) {  // 날라리 점수
        cin >> score[i];
    }

    for (int i = 2; i <= n; ++i) {  // 트리 구현
        int parent;
        cin >> parent;
        tree[parent].push_back(i);
    }
    return 0;
}
