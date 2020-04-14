//F.cpp
#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    int q;
    cin >> q;
    while (q--) {
        cin >> n >> m;
        vector<string> g(n), col(n);
        vector<int> to(n * m), dgr(n * m);
        vector<vector<int>> e(n * m);
        for (int i = 0; i < n; ++i) cin >> col[i];
        for (int i = 0; i < n; ++i) cin >> g[i];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int xx = i, yy = j;
                if (g[i][j] == 'U') --xx;
                else if (g[i][j] == 'D') ++xx;
                else if (g[i][j] == 'L') --yy;
                else ++yy;
                to[i * m + j] = xx * m + yy;
                ++dgr[to[i * m + j]];
            }
        }
        function<void(int)> cut_chain = [&](int x) {
            --dgr[x];
            e[to[x]].emplace_back(x);
            if (--dgr[to[x]] == 0)
                cut_chain(to[x]);
        };
        for (int i = 0; i < n * m; ++i) {
            if (!dgr[i])
                cut_chain(i);
        }
        int ans1 = 0, ans2 = 0;
        for (int i = 0; i < n * m; ++i) {
            if (dgr[i] == 1) {
                int cnt = 1;
                for (int j = to[i]; j != i; j = to[j]) {
                    e[to[j]].emplace_back(j);
                    ++cnt;
                }
                ans1 += cnt;
                vector<bool> cc(cnt);
                function<void(int, int)> dfs = [&](int u, int dpt) {
                    dgr[u] = -1;
                    if (col[u / m][u % m] == '0') cc[dpt % cnt] = true;
                    for (int v : e[u])
                        dfs(v, dpt + 1);
                };
                dfs(i, 0);
                ans2 += count(cc.begin(), cc.end(), true);
            }
        }

        cout << ans1 << ' ' << ans2 << endl;
    }
    return 0;
}