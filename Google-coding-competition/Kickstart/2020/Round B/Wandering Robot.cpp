//Wandering Robot.cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

double ln_fac[N], p[N];

double calc(int k, int n) {
    return exp(ln_fac[n] - ln_fac[k] - ln_fac[n - k] - p[n]);
}

int main() {
    p[1] = log(2);
    for (int i = 2; i < N; ++i) {
        ln_fac[i] = ln_fac[i - 1] + log(i);
        p[i] = p[i - 1] + p[1];
    }
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        int x, y, x1, y1, x2, y2;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;
        --x, --y, --x1, --y1, --x2, --y2;
        double ans = 0;
        auto go = [&]() {
            int tx = x2, ty = y1;
            if (x2 < x) {
                double fl = 1;
                while (ty) {
                    ty--, tx++;
                    if (tx > x) {
                        fl = 0.5;
                        --tx;
                    }
                    ans += fl * calc(tx, ty + tx);
                }
            }
        };
        go();
        swap(x, y); swap(x1, y1); swap(x2, y2);
        go();
        printf("Case #%d: %.7lf\n", cas, ans);
    }
    return 0;
}