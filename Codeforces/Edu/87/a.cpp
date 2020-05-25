//a.cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int q;
    cin >> q;
    while (q--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a <= b) {
            cout << b << endl;
            continue;
        }
        if (c <= d) {
            cout << -1 << endl;
            continue;;
        }
        ll ans = b;
        a -= b;
        ans += c * (a / (c - d));
        if (a % (c - d)) ans += c;
        cout << ans << endl;
    }
    return 0;
}