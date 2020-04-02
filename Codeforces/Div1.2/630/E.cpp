//E.cpp
#include <bits/stdc++.h>
using namespace std;

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod; b >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef MYDEBUG
    freopen("../0in.txt", "r", stdin);
//    freopen("../0out.txt", "w", stdout);
#endif

    ll l, r, n, m;
    cin >> n >> m >> l >> r;
    n *= m;
    if (n & 1) {
        cout << qpow(r - l + 1, n) << endl;
    } else {
        ll odd = (r + 1) / 2 - l / 2;
        ll even = r / 2 - (l - 1) / 2;
        cout << ((qpow(even + odd, n) + qpow(even - odd, n)) * (mod + 1) / 2) % mod << endl;
    }
    return 0;
}