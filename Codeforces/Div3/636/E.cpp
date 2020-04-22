//F.cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m, a, b, c;
        cin >> n >> m >> a >> b >> c;
        vector<vi> g(n + 1);
        vector<vi> d(3, vi(n + 1, -1));
        vector<ll> p(m + 1);
        for (int i = 1; i <= m; ++i)
            cin >> p[i];
        sort(p.begin(), p.begin() + m + 1);
        for (int i = 1; i <= m; ++i)
            p[i] += p[i - 1];
        for (int i = 0, u, v; i < m; ++i) {
            cin >> u >> v;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        auto bfs = [&](int s, int i) {
            queue<int> Q;
            Q.emplace(s);
            d[i][s] = 0;
            while (!Q.empty()) {
                int u = Q.front();
                Q.pop();
                for (int v : g[u]) {
                    if (d[i][v] == -1) {
                        d[i][v] = d[i][u] + 1;
                        Q.emplace(v);
                    }
                }
            }
        };
        bfs(a, 0);
        bfs(b, 1);
        bfs(c, 2);
        ll ans = INF64;
        for (int i = 1; i <= n; ++i) {
            if (d[2][i] + d[1][i] + d[0][i] > m) continue;
            ll tt = p[d[1][i]] + p[d[2][i] + d[1][i] + d[0][i]];
            ans = min(ans, tt);
        }
        cout << ans << endl;
    }
    return 0;
}