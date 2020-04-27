//A.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        ll a, b, x, y;
        cin >> x >> y >> a >> b;

        ll ans = 0;
        if (a * 2 >= b) {
            int t = min(y, x);
            x -= t, y -= t;
            ans = t * b + (x + y) * a;
        } else
            ans = (x + y) * a;
        cout << ans << endl;
    }
    return 0;
}