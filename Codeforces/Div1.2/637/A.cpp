//A.cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;

int cc[N];

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;
        fill(cc, cc + c + d + 1, 0);
        ++cc[max(0, (a - b) * n)];
        --cc[n * (a + b) + 1];
        int f = 0;
        for (int i = 1; i <= c + d; ++i) {
            cc[i] += cc[i - 1];
            if (i >= c - d && cc[i]) {
                f = 1;
                break;
            }
        }
        if (f) puts("Yes");
        else puts("No");
    }
    return 0;
}