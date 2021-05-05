#include <climits>
#include <cmath>
#include <iostream>
using namespace std;

int g;  // 100000
bool flag = false;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> g;  // 현재^2-원래^2

    int l = 1, r = 1;
    while (l <= r && r <= 100000) {
        int calc = pow(r, 2) - pow(l, 2);
        if (calc < g)
            r++;
        else if (calc == g) {
            flag = true;
            cout << r << '\n';
            r++;
        } else
            l++;
    }

    if (!flag) cout << -1;
    return 0;
}
