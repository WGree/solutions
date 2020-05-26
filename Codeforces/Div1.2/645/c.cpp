//c.cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int q;
    cin >> q;
    while (q--) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        y2 -= y1; x2 -= x1;
        cout << x2 * y2 + 1 << endl;
    }
    return 0;
}