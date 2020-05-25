//e.cpp
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const int N = 5e3 + 1;

int col[N], dp[N][N], bac[N][N];
vector<int> g[N];
vector<vi> vv[2];

void dfs(int u, int c) {
    col[u] = c;
    vv[c].back().emplace_back(u);
    for (int v : g[u]) {
        if (col[v] == -1)
            dfs(v, c ^ 1);
        else if (col[v] == c) {
            cout << "NO" << endl;
            exit(0);
        }
    }
}

//#define endl '\n'
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int a, b, c;
    cin >> a >> b >> c;
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    fill(col, col + n + 1, -1);
    vv[0].emplace_back();
    vv[1].emplace_back();
    for (int i = 1; i <= n; ++i) {
        if (col[i] == -1) {
            vv[0].emplace_back();
            vv[1].emplace_back();
            dfs(i, 0);
        }
    }

    m = vv[0].size() - 1;
    dp[0][0] = 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = n; j >= 0; --j) {
            int szz = vv[1][i].size();
            if (j >= szz) dp[i][j] |= dp[i - 1][j - szz], bac[i][j] = dp[i][j];
            szz = vv[0][i].size();
            if (j >= szz) dp[i][j] |= dp[i - 1][j - szz];
        }
    }
    if (!dp[m][b]) {
        cout << "NO" << endl;
        return 0;
    }
    int x = b;
    for (int i = m; i > 0; --i) {
        int tp = 0;
        if (bac[i][x]) tp ^= 1;
        x -= vv[tp][i].size();
        for (int v : vv[0][i]) col[v] = tp;
        tp ^= 1;
        for (int v : vv[1][i]) col[v] = tp;
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; ++i) {
        if (col[i]) {
            if (a--) cout << 1;
            else cout << 3;
        } else cout << 2;
    }
    cout << endl;
    return 0;
}