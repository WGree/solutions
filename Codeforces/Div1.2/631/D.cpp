//D.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int q, m, n;
    cin >> q;
    while (q--) {
        cin >> n >> m;
        vector<int> dp(35), cnt(35);
        for (int i = 0, j = 1; i < 31; ++i) {
            cnt[i] = (min(n, (j << 1) - 1) + 1 - j) % m;
            if (cnt[i] < 0) {
                cnt[i] = 0;
                break;
            }
            j <<= 1;
        }
        for (int i = 1; i < 32; ++i)
            dp[i] = (ll(dp[i - 1] + 1) * cnt[i - 1] + dp[i - 1]) % m;
        cout << dp[31] << endl;
    }
    return 0;
}