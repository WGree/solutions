//e.cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, a, r, m;
    cin >> n >> a >> r >> m;
    m = min(m, a + r);
    vector<int> h(n);
    for (int &i : h) cin >> i;
    auto calc = [&](int x) {
        ll p = 0, q = 0;
        for (int i = 0; i < n; ++i) {
            if (h[i] < x) p += x - h[i];
            else q += h[i] - x;
        }
        if (p < q) return p * m + (q - p) * r;
        else return q * m + (p - q) * a;
    };
    int mid, l = 0, rr = 1e9;
    while (rr - l > 3) {
        mid = (l + rr) / 2;
        if (calc(mid) < calc(mid + 1))
            rr = mid + 1;
        else
            l = mid;
    }
    ll ans = 1e18;
    for (int i = l; i <= rr; ++i) {
        ans = min(ans, calc(i));
    }
    cout << ans << endl;
    return 0;
}