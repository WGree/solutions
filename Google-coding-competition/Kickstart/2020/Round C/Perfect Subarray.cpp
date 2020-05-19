//Perfect Subarray.cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 1;

int a[N], cnt[N * 200];

int main() {
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        int n, mi = 0, mx = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            if (a[i] < 0) mi += a[i];
            else mx += a[i];
        }
        mi = -mi;
        fill(cnt, cnt + mx + 1 + mi, 0);
        cnt[mi] = 1;
        ll ans = 0;
        for (int i = 1, pre = 0; i <= n; ++i) {
            pre += a[i];
            for (int j = 0; j * j <= mx; ++j) {
                int t = (pre - j * j) + mi;
                if (t < 0) break;
                ans += cnt[t];
            }
            ++cnt[pre + mi];
        }
        printf("Case #%d: %lld\n", cas, ans);
    }
    return 0;
}