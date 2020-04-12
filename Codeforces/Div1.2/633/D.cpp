#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int has[N][2], f;
vector<int> g[N];

void dfs(int u, int fa = 0) {
    if (g[u].size() == 1) {
        has[u][0] = 1;
        return;
    }
    for (int v : g[u]) {
        if (v == fa) continue;
        dfs(v, u);
        has[u][1] |= has[v][0];
        has[u][0] |= has[v][1];
    }
    if (has[u][0] && has[u][1]) f = 1;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    int ans = 0, rt = 1;
    for (int i = 1; i <= n; ++i) {
        int t = -1;
        for (int v : g[i]) {
            if (g[v].size() == 1) ++t;
        }
        if (g[i].size() > 1) rt = i;
        if (t > 0) ans += t;
    }
    dfs(rt);

    ans = n - 1 - ans;
    if (f) cout << "3 ";
    else cout << "1 ";
    cout << ans << endl;
    return 0;
}