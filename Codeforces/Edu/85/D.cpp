//D.cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n;
ll cnt[N];

int calc(ll x) {
    if (x > cnt[n]) return 1;
    int ptr = lower_bound(cnt, cnt + n, x) - cnt;
    int t = x - cnt[ptr - 1];
    if (t & 1) return ptr;
    else return t / 2 + ptr;
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        ll l, r;
        cin >> n >> l >> r;
        for (int i = 1; i <= n; ++i) {
            cnt[i] = cnt[i - 1] + 2 * (n - i);
        }
        for (ll i = l; i <= r; ++i) {
            cout << calc(i) << ' ';
        }
        cout << endl;
    }
    return 0;
}