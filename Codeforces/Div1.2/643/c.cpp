//c.cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    ll ans = 0;
    for (int i = a; i <= b; ++i) {
        int l1 = i + b, r1 = i + c;
        int l2 = c + 1, r2 = d + 1;
        l1 = max(l1, l2);
        r2 = min(r1, r2);
        if (l1 > r1 || l2 > r2)
            continue;
        if (l1 >= r2) ans += ll(r1 - l1 + 1) * (r2 - l2 + 1);
        else ans += ll(l1 - l2 + 1 + r2 - l2) * (r2 - l1) / 2 + ll(r1 - r2 + 1) * (r2 - l2 + 1);
    }
    cout << ans << endl;
    return 0;
}