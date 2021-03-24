#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
#define INF 2109876543

struct El {
    int a, b, height;
    El(int _a, int _b, int _height) : a(_a), b(_b), height(_height){};
};

bool cmp(const El& e1, const El& e2) {
    return e1.height < e2.height;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    vector<El> elCase;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            elCase.push_back(El(i, j, v[i] + v[j]));
        }
    }
    sort(elCase.begin(), elCase.end(), cmp);

    int diff = INF;
    for (int i = 0; i < elCase.size() - 1; ++i) {
        for (int j = i + 1; j < elCase.size(); ++j) {
            if (elCase[i].a != elCase[j].a && elCase[i].b != elCase[j].b && elCase[i].a != elCase[j].b && elCase[i].b != elCase[j].a) {
                diff = min(diff, elCase[j].height - elCase[i].height);
                break;
            }
        }
    }

    cout << diff;
    return 0;
}
