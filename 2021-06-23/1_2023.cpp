#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> odd{1, 3, 5, 7, 9};

bool isPrime(int num) {
    if (num == 1)
        return false;
    else if (num == 2)
        return true;
    for (int i = 2; i * i <= num; ++i) {
        if ((num % i) == 0) return false;
    }
    return true;
}

void go(int num, int remain) {
    if (remain == 1) {
        cout << num << '\n';
        return;
    }
    for (int i = 0; i < 5; ++i) {
        int nNum = num * 10 + odd[i];
        if (isPrime(nNum)) go(nNum, remain - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    go(2, n);  // 2333, 2339, 2393, 2399, 2939
    go(3, n);
    go(5, n);
    go(7, n);
    return 0;
}
