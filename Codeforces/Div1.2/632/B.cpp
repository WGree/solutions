//B.cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int a[N], b[N], has[N][2];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            has[i][0] = has[i - 1][0];
            has[i][1] = has[i - 1][1];
            if (a[i] > 0) has[i][0] = 1;
            else if (a[i] < 0) has[i][1] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            cin >> b[i];
        }
        int f = 1;
        for (int i = n; i > 0; --i) {
            if (b[i] == a[i]) continue;
            else if (b[i] < a[i]) {
                if (!has[i - 1][1]) {
                    f = 0;
                    break;
                }
            } else if (!has[i - 1][0]) {
                f = 0;
                break;
            }
        }
        if (f) puts("YES");
        else puts("NO");
    }
    return 0;
}