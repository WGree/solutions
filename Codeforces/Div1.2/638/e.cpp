//e.cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;
    ll suma = 0, sumb = 0;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        suma += a[i];
        sumb += b[i];
    }
    ll sum = suma + sumb;

    bitset<1024> dp(1), dp2;
    for (int i = 0; i < n; ++i) {
        dp2 = (dp << a[i] % k) | (dp >> (k - a[i] % k));
        for (int j = 0, ed = min(k - 1, a[i]); j <= ed; ++j)
            if ((a[i] - j) % k + b[i] >= k)
                dp2 |= (dp << j) | (dp >> (k - j));
        dp = dp2;
        dp2.reset();
    }
    ll ans = 0;
    for (int i = 0; i < k; ++i) {
        if (dp[i]) {
            ans = (sum - i) / k;
            break;
        }
    }
    cout << ans << endl;
}