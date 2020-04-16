//E.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    s = ' ' + s, t = ' ' + t;
    vector<vector<int>> dp(n + 2, vector<int> (n + 2));
    for (int i = 1; i <= n + 1; ++i) {
        dp[i][i - 1] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        for (int l = 1; l <= n - i + 1; ++l) {
            int r = l + i - 1;
            if (l > m || s[i] == t[l]) dp[l][r] = (dp[l][r] + dp[l + 1][r]) % mod;
            if (r > m || s[i] == t[r]) dp[l][r] = (dp[l][r] + dp[l][r - 1]) % mod;
        }
    }
    
    int ans = 0;
    for (int i = m; i <= n; ++i) {
        ans = (ans + dp[1][i]) % mod;
    }
    cout << ans << endl;
    return 0;
}