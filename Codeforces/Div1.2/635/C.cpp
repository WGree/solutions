//C.cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;

ll cnt[N], dpt[N];
vector<int> g[N];
vector<pii> ps;

void dfs(int u, int fa) {
    for (int v : g[u]) {
        if (v == fa) continue;
        dpt[v] = dpt[u] + 1;
        dfs(v, u);
        cnt[u] += cnt[v];
    }
    ++cnt[u];
    ps.emplace_back(u, (dpt[u] - 1) * cnt[u] - dpt[u] * (cnt[u] - 1));
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    dpt[1] = 1;
    dfs(1, 0);
    ll ans = 0;
    sort(ps.begin(), ps.end(), [&](pii a, pii b) { return a.second > b.second; });
    for (int i = 0; i < k; ++i) {
        ans += ps[i].second;
    }
    cout << ans << endl;
    return 0;
}