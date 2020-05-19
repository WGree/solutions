//Countdown.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        int n, k, ans = 0;
        cin >> n >> k;
        vector<int> a(n);
        for (int &i : a) cin >> i;
        auto check = [&](int &i, int r) {
            int t = k;
            while (i < r) {
                if (a[i] != t)
                    return false;
                --t;++i;
            }
            return true;
        };
        for (int i = 0; i + k <= n; ++i) {
            if (a[i] == k) {
                if (check(i, i + k))
                    ++ans;
                --i;
            }
        }
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}