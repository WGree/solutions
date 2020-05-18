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
        if (a <= b)
            cout << b << endl;
        else if (c - d <= 0)
            cout << -1 << endl;
        else {
            a -= b;
            ll ans = b;
            int t = a / (c - d);
            ans += t * c;
            if (a % (c - d))
                ans += c;
            cout << ans << endl;
        }
    }
    return 0;
}