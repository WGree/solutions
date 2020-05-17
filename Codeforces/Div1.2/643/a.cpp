//a.cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int q;
    cin >> q;
    while (q--) {
        ll n, k;
        cin >> n >> k;
        while (--k) {
            int mi = 10, mx = 0;
            ll t = n;
            while (t) {
                mi = min(mi, int(t % 10));
                mx = max(mx, int(t % 10));
                t /= 10;
            }
            if (mi == 0)
                break;
            n += mi * mx;
        }
        cout << n << endl;
    }
    return 0;
}