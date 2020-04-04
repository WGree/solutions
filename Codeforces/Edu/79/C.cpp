//C.cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

int pos[N];

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n, m, la = 0;
        cin >> n >> m;
        for (int i = 1, t; i <= n; ++i) {
            cin >> t;
            pos[t] = i;
        }
        ll ans = 0;
        for (int i = 1, t; i <= m; ++i) {
            cin >> t;
            if (pos[t] < la) ++ans;
            else ans += 2 * (pos[t] - i) + 1;
            la = max(la, pos[t]);
        }
        cout << ans << endl;
    }
    return 0;
}