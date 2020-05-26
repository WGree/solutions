//d.cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    auto calc = [](ll x) { return (1 + x) * x / 2; };

    int n;
    ll x;
    cin >> n >> x;
    vector<int> d(n * 2 + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
        d[i + n] = d[i];
    }
    n *= 2;
    ll tx = 0, ans = 0, a = 0, b = 1, tmp = 0;
    for (int i = 1; i <= n; ++i) {
        tx += d[i];
        tmp += calc(d[i]);
        while (tx > x) {
            ll t = min(tx - x, d[b] - a);
            tx -= t;
            tmp -= calc(t + a) - calc(a);
            a += t;
            if (a == d[b]) {
                ++b;
                a = 0;
            }
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}