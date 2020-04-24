//E.cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;

int main() {
    using rec = tuple<int, int, int>;

    int n, m, r, g;
    cin >> n >> m;
    vector<int> d(m);
    for (int &i : d) cin >> i;
    sort(d.begin(), d.end());
    cin >> g >> r;

    vector<vector<int>> dis(m, vector<int> (g + 1, -1));
    deque<rec> q;
    q.emplace_back(0, 0, 0);
    while (!q.empty()) {
        auto[u, t, _dis] = q.front();
        q.pop_front();
        if (dis[u][t] != -1)
            continue;
        dis[u][t] = _dis;
        if (t == g)
            q.emplace_back(u, 0, _dis + 1);
        if (u != 0 && t + d[u] - d[u - 1] <= g)
            q.emplace_front(u - 1, t + d[u] - d[u - 1], _dis);
        if (u != m - 1 && t + d[u + 1] - d[u] <= g)
            q.emplace_front(u + 1, t + d[u + 1] - d[u], _dis);
    }
    ll ans = INF64;
    for (int i = 1; i <= g; ++i) {
        if (dis[m - 1][i] != -1) {
            ans = min(ans, ll(g + r) * dis[m - 1][i] + i);
        }
    }
    if (ans == INF64)
        ans = -1;
    cout << ans << endl;
    return 0;
}