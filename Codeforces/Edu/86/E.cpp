//E.cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int N = 5e5 + 5;

ll qpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

ll fac[N], inv[N];

int main() {
    fac[0] = 1;
    for (int i = 1; i < N; ++i)
        fac[i] = fac[i - 1] * i % mod;
    inv[N - 1] = qpow(fac[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; --i)
        inv[i] = inv[i + 1] * (i + 1) % mod;
    auto C = [&](int n, int m) {
        if (m < 0 | m > n) return 0ll;
        return fac[n] * inv[m] % mod * inv[n - m] % mod;
    };

    int n;
    ll k;
    cin >> n >> k;
    if (k >= n)
        cout << 0 << endl;
    else if (k == 0)
        cout << fac[n] << endl;
    else {
        ll ans = 0;
        for (int i = 0; i <= n - k; ++i) {
            ll t = C(n - k, i) * qpow(n - k - i, n);
            if (i & 1) ans = (ans - t) % mod;
            else ans = (ans + t) % mod;
        }
        if (ans < mod) ans += mod;
        ans = ans * inv[n - k] % mod;
        ans = 2 * ans * C(n, n - k) % mod * fac[n - k] % mod;
        cout << ans << endl;
    }
    return 0;
}