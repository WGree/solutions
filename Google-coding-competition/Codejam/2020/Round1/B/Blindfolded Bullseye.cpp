//Blindfolded Bullseye.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    auto sd = [&](int x, int y) {
        cout << x << ' ' << y << endl;
        os << x << ' ' << y << endl;
        string s;
        cin >> s;
        if (s == "CENTER")
            return 1;
        if (s == "HIT")
            return 2;
        return 0;
    };

    int T, a, b;
    cin >> T >> a >> b;
    for (int cas = 1; cas <= T; ++cas) {
        int x, y, f = 0;
        string s;
        for (x = -1e9 + 1e9 / 2; x < 1e9; x += 1e9 / 2) {
            for (y = -1e9 + 1e9 / 2; y < 1e9; y += 1e9 / 2) {
                cout << x << ' ' << y << endl;
                cin >> s;
                if (s == "CENTER") goto nex;
                if (s == "HIT") {
                    f = 2;
                    break;
                }
            }
            if (f) break;
        }
        if (f == 2) {
            int l = -1e9, r = x, x1, x2, y1, y2, mid, res;
            while (l <= r) {
                mid = (l + r) / 2;
                if (res = sd(mid, y)) {
                    if (res == 1) goto nex;
                    r = mid - 1;
                    x1 = mid;
                } else
                    l = mid + 1;
            }
            l = x, r = 1e9;
            while (l <= r) {
                mid = (l + r) / 2;
                if (res = sd(mid, y)) {
                    if (res == 1) goto nex;
                    l = mid + 1;
                    x2 = mid;
                } else
                    r = mid - 1;
            }
            l = -1e9, r = y;
            while (l <= r) {
                mid = (l + r) / 2;
                if (res = sd(x, mid)) {
                    if (res == 1) goto nex;
                    r = mid - 1;
                    y1 = mid;
                } else
                    l = mid + 1;
            }
            l = y, r = 1e9;
            while (l <= r) {
                mid = (l + r) / 2;
                if (res = sd(x, mid)) {
                    if (res == 1) goto nex;
                    l = mid + 1;
                    y2 = mid;
                } else
                    r = mid - 1;
            }
            x = (x1 + x2) / 2;
            y = (y1 + y2) / 2;
        } else
            return 3;
        for (int i = -2; i <= 2; ++i) {
            for (int j = -2; j <= 2; ++j) {
                cout << x + i << ' ' << y + j << endl;
                cin >> s;
                if (s == "CENTER") goto nex;
            }
        }
        nex:;
    }
    return 0;
}