#include <iostream>
#include <string>
using namespace std;

const int MAX = 26;
int n;             // 2~26
bool a[MAX][MAX];  // i -> j 증명

// 플로이드와샬로 i->j 사이의 중간 논증을 증명해준다.(i->k->j)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    cin.ignore();  // cin과 getline 같이 쓸 때 '\n' 꼭 플러싱 해주기

    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            if (i == j)
                a[i][j] = true;
            else
                a[i][j] = false;
        }
    }  // i==j이면 무조건 옳은 논증

    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);
        int from = s.front() - 'a';
        int to = s.back() - 'a';
        a[from][to] = true;
    }

    for (int k = 0; k < MAX; ++k) {
        for (int i = 0; i < MAX; ++i) {
            for (int j = 0; j < MAX; ++j) {
                if (a[i][k] && a[k][j]) {  // 플로이드로 i->k->j 증명 추가
                    a[i][j] = true;
                }
            }
        }
    }

    int m;
    cin >> m;
    cin.ignore();
    while (m--) {
        string s;
        getline(cin, s);
        int from = s.front() - 'a';
        int to = s.back() - 'a';

        if (a[from][to]) {
            cout << 'T' << '\n';
        } else {
            cout << 'F' << '\n';
        }
    }

    return 0;
}
