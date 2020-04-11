//C.cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;

ll a[N], b[N], ss[N];

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        ll sum = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i] >> b[i];
            ss[i] = max(0ll, a[i] - b[i - 1]);
        }
        ss[1] = max(0ll, a[1] - b[n]);
        for (int i = 1; i <= n; ++i) {
            sum += ss[i];
        }
        ll ans = INF64;
        for (int i = 1; i <= n; ++i) {
            ans = min(ans, sum - ss[i] + a[i]);
        }
        cout << ans << endl;
    }
    return 0;
}