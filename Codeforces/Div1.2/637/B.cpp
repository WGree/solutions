//B.cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int cc[N], a[N];

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            cin >> cc[i];
            a[i] = 0;
        }
        cc[n + 1] = cc[0] = INF32;
        for (int i = 1; i <= n; ++i) {
            if (cc[i] > cc[i - 1] && cc[i] > cc[i + 1]) {
                a[i] = 1;
            }
        }
        int ans = 0, tp = 0, id;
        for (int i = n; i > n + 1 - k; --i) {
            if (a[i]) ++tp;
        }
        for (int i = n + 1 - k; i > 0; --i) {
            if (ans <= tp) {
                id = i;
                ans = tp;
            }
            tp += a[i] - a[i + k - 2];
        }
        cout << ans + 1 << ' ' << id << endl;
    }
    return 0;
}