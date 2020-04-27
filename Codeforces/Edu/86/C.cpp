//C.cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int g, a, b;

ll calc(ll x) {
    ll ret = x / g * (g - b);
    ret += max(0ll, x % g - b + 1);
    return ret;
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> a >> b >> t;
        if (a > b) swap(a, b);
        g = a * b / __gcd(a, b);
        while (t--) {
            ll l, r;
            cin >> l >> r;
            cout << calc(r) - calc(l - 1) << ' ';
        }
        cout << endl;
    }
    return 0;
}