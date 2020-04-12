//C.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        ll mx = -1e9, mxx = 0;
        cin >> n;
        vector<ll> a(n);
        for (ll &i : a) cin >> i;
        for (int i = 0; i < n; ++i) {
            mx = max(mx, a[i]);
            mxx = max(mxx, mx - a[i]);
        }

        ll ans = 0;
        for (int i = 0; i < 33; ++i) {
            if ((mxx >> i) & 1)
                ans = i + 1;
        }
        cout << ans << endl;
    }
    return 0;
}