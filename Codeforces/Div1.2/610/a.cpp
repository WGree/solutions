//a.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int a, b, c, r;
        cin >> a >> b >> c >> r;
        if (a > b) swap(a, b);
        int ans = 0;
        if (c - r > a)
            ans += min(b, c - r) - a;
        if (c + r < b)
            ans += b - max(a, c + r);
        cout << ans << endl;
    }
    return 0;
}