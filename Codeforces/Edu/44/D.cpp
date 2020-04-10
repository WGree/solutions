//D.cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll check(ll x) {
    ll t = (x + 1) / 2;
    ll ret = t * (t + 1);
    if (x & 1) {
        ret -= t;
    }
    return ret;
}

int main() {
    ll n, H;
    cin >> n >> H;
    ll ttt = (H + 1) * H / 2;
    if (H > 2e9 || (H + 1) * H / 2 > n) {
        ll mid, ans = 0, l = 0, r = min(ll(2e9), H);
        while (l <= r) {
            mid = (l + r) / 2;
            if (mid * (mid + 1) / 2 >= n) {
                r = mid - 1;
                ans = mid;
            } else
                l = mid + 1;
        }
        cout << ans << endl;
    } else {
        n -= (H - 1) * H / 2;
        ll mid, ans = 0, l = 0, r = 2e9;
        while (l <= r) {
            mid = (l + r) / 2;
            if (check(mid) + mid * (H - 1) >= n) {
                r = mid - 1;
                ans = mid;
            } else
                l = mid + 1;
        }
        cout << ans + H - 1 << endl;
    }
    return 0;
}