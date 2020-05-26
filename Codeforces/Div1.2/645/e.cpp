//e.cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n + 5), sum(n + 5);
    ll x, t = 0;
    int m = (n + 1) / 2;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
        t += a[i];
    }
    cin >> x;
    if (x > 0) {
        if (t + x * (n / 2) > 0) {
            cout << n << endl;
            return 0;
        } else {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int i = n; i >= 0; --i) {
        if (i > m) a[i] = x;
        sum[i] = sum[i + 1] + a[i];
    }
    int ans = -1;
    for (int i = m, j; i >= 0; --i) {
        if (sum[i] > 0) {
            int f = 1;
            for (j = i - 1; j > 0; --j) {
                if (sum[j] - sum[j + n - i + 1] <= 0) {
                    f = 0;
                    break;
                }
            }
            if (f == 1) {
                ans = n - i + 1;
                break;;
            }
            i = j;
        }
    }
    cout << ans << endl;
    return 0;
}