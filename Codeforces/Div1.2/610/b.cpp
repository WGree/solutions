//b.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n, p, k;
        cin >> n >> p >> k;
        vector<int> a(n + 1), dp(n + 1);
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        sort(a.begin() + 1, a.end());
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1] + a[i];
            if (i >= k) dp[i] = min(dp[i], dp[i - k] + a[i]);
            if (dp[i] <= p) ans = i;
        }
        cout << ans << endl;
    }
    return 0;
}