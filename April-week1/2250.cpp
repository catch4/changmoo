#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 10000;
int n, root;  // 노드갯수10000, 루트노드
int cnt = 1;  // inorder 순회 시작노드(왼쪽-가운데-오른쪽)
vector<int> tree[MAX + 1];
vector<int> depth[MAX + 1];
vector<int> parent(MAX + 1);
vector<bool> hasParent(MAX + 1);
// 이진트리에서 너비가 가장 넓은 레벨을 구하고, 1~레벨까지 모든 노드의 갯수를 구한다

void inorder(int node, int level) {
    if (tree[node][0] != -1) inorder(tree[node][0], level + 1);
    depth[level].push_back(cnt++);
    if (tree[node][1] != -1) inorder(tree[node][1], level + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int mid, left, right;
        cin >> mid >> left >> right;
        tree[mid].push_back(left);
        tree[mid].push_back(right);
        if (left != -1) hasParent[left] = true;
        if (right != -1) hasParent[right] = true;
    }

    for (int i = 1; i <= n; ++i) {
        if (!hasParent[i]) {
            root = i;  // 부모가 없는 루트노드
            break;
        }
    }

    inorder(root, 1);  // 각 노드 레벨을 depth에 저장

    int maxWidth = 0, lv = 1;
    for (int i = 1; i <= MAX; ++i) {
        if (depth[i].empty()) continue;

        sort(depth[i].begin(), depth[i].end());
        int width = depth[i].back() - depth[i].front() + 1;
        if (width > maxWidth) {
            maxWidth = width;
            lv = i;
        }
    }

    cout << lv << ' ' << maxWidth;
    return 0;
}
