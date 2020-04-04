#include <bits/stdc++.h>
using namespace std;

int ans[55], fa[55], vis[55];
ll dp[55], fac[55];

inline ll calc(int x) {
    x -= 2;
    if (x < 0) return 1;
    return fac[x];
}

void init() {
    fac[0] = 1;
    for (int i = 1; i < 20; ++i)
        fac[i] = fac[i - 1] * i;
    for (int i = 20; i <= 50; ++i)
        fac[i] = 1e18;

    dp[0] = 1;
    for (int i = 1; i < 22; ++i) {
        for (int j = 0; j < i; ++j)
            dp[i] += dp[j] * calc(i - j);
    }
    for (int i = 22; i <= 50; ++i) {
        dp[i] = 1e18;
    }
}

int fi(int x) {
    if (x != fa[x])
        return fa[x] = fi(fa[x]);
    return x;
}

void permute(int l, int r, ll rk) {
    ans[l] = r;
    vis[r] = 1;
    int x = r - l - 2;
    for (int i = l + 1; i <= r; ++i) {
        for (int j = l; j <= r; ++j) {
            if (i == r && !vis[j]) {
                ans[i] = j;
                break;
            }
            if (vis[j] || fi(i) == fi(j)) continue;
            if (x < 0) x = 0;
            if (fac[x] >= rk) {
                --x;
                ans[i] = vis[j] = j;
                fa[fi(j)] = fi(i);
                break;
            } else
                rk -= fac[x];
        }
    }
}

int main() {
    init();
    int q;
    cin >> q;
    while (q--) {
        int n;
        ll k;
        cin >> n >> k;
        if (k > dp[n]) {
            cout << -1 << endl;
            continue;
        }
        for (int i = 1; i <= n; ++i) {
            vis[i] = 0;
            fa[i] = i;
        }
        for (int l = 1, r; l <= n; l = r + 1) {
            for (r = l; r <= n; ++r) {
                ll term = calc(r - l + 1) * dp[n - r];
                if (term >= k)
                    break;
                k -= term;
            }
            ll rk = (k - 1) / dp[n - r] + 1;
            k = (k - 1) % dp[n - r] + 1;
            permute(l, r, rk);

        }
        for (int i = 1; i <= n; ++i)
            cout << ans[i] << ' ';
        cout << endl;
    }
    return 0;
}