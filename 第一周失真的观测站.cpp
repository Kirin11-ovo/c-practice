#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n), b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    // 从编号最小的观测站开始尝试删除
    for (int deleted = 0; deleted < n; deleted++) {
        long long last = LLONG_MIN;
        bool possible = true;

        // 按原顺序检查没有被删除的观测站
        for (int i = 0; i < n; i++) {
            if (i == deleted) {
                continue;
            }

            bool canChooseA = (a[i] > last);
            bool canChooseB = (b[i] > last);

            if (canChooseA && canChooseB) {
                // 两个读数都能选时，选较小的，给后面的数留更多空间
                last = min(a[i], b[i]);
            } else if (canChooseA) {
                last = a[i];
            } else if (canChooseB) {
                last = b[i];
            } else {
                possible = false;
                break;
            }
        }

        if (possible) {
            cout << deleted + 1 << '\n';  // 题目中的编号从 1 开始
            return 0;
        }
    }

    cout << -1 << '\n';
    return 0;
}
