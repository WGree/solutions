//F.cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int mx;
vector<pii> ans;
vector<int> g[N];

void dfs(int u, int fa, int t) {
    ans.emplace_back(u, t);
    int cur = t, res = g[u].size() - (u != 1);
    for (int v : g[u]) {
        if (v == fa)continue;
        if (cur == mx) {
            cur = t - 1 - res;
            ans.emplace_back(u, cur);
        }
        dfs(v, u, cur + 1);
        ++cur; --res;
        ans.emplace_back(u, cur);
    }
    if (u != 1 && cur != t - 1)
        ans.emplace_back(u, t - 1);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        mx = max(mx, int(g[i].size()));
    }
    dfs(1, 0, 0);
    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i.first << ' ' << i.second << endl;
    return 0;
}