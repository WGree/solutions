//C.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, f = 0;
    cin >> n;
    map<ll, ll> mp;
    ll pre = 0, ans = 0, l = 1;
    mp[0] = 0;
    for (int i = 1, t; i <= n; ++i) {
        cin >> t;
        pre += t;
        if (mp.count(pre)) {
            if (mp[pre] + 1 >= l) {
                if (f) ans -= min(mp[pre] + 1, l) * (n - i + 1);
                l = mp[pre] + 1;
                ans += l * (n - i + 1);
                f = 1;
            }
        }
        mp[pre] = i;
    }
    ans = ll(n + 1) * n / 2 - ans;
    cout << ans << endl;
    return 0;
}