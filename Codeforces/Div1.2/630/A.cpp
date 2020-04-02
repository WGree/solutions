//A.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef MYDEBUG
    freopen("../0in.txt", "r", stdin);
//    freopen("../0out.txt", "w", stdout);
#endif

    int q;
    cin >> q;
    while (q--) {
        int a, b, c, d, x, y, x1, y1, x2, y2, f = 0;
        cin >> a >> b >> c >> d
            >> x >> y >> x1 >> y1 >> x2 >> y2;
        if ((x1 == x2) && (a || b))
            f = 1;
        if ((y1 == y2) && (c || d))
            f = 1;
        b -= a, d -= c;
        if (b + x < x1 || b + x > x2)
            f = 1;
        if (d + y < y1 || d + y > y2)
            f = 1;
        if (f)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}