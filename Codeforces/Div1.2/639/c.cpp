//c.cpp
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int n, m;
bool typo(const vector<vi> &g, vi &ind) {
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (!ind[i])
            q.emplace(i);
    }
    int cnt = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ++cnt;
        for (int v : g[u]) {
            --ind[v];
            if (!ind[v])
                q.emplace(v);
        }
    }
    return cnt == n;
}

void bfs(const vector<vi> &g, vi &vis, int s) {
    queue<int> q;
    q.emplace(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int v : g[u])
            q.emplace(v);
    }
}

int main() {
    cin >> n >> m;
    vector<vi> g(n + 1), rg(n + 1);
    vi ind(n + 1);
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        g[u].emplace_back(v);
        rg[v].emplace_back(u);
        ++ind[v];
    }
    if (!typo(g, ind)) {
        cout << -1 << endl;
        return 0;
    }
    int cnt = 0;
    string ans;
    vi vis(n + 1), rvis(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (vis[i] || rvis[i])
            ans += "E";
        else {
            ++cnt;
            ans += "A";
        }
        bfs(g, vis, i);
        bfs(rg, rvis, i);
    }
    cout << cnt << endl << ans << endl;
    return 0;
}