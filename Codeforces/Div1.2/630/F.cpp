//F.cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

ll dp[N][3];
vector<int> g[N];

void dfs(int u, int fa = 0) {
    dp[u][0] = dp[u][1] = dp[u][2] = 1;
    for (int v : g[u]) {
        if (v == fa) continue;
        dfs(v, u);
        ll num1 = dp[v][0] + dp[v][1] - dp[v][2];
        ll num0 = dp[v][0] + dp[v][1];
        dp[u][0] = dp[u][0] * (num1 + num0) % mod;
        dp[u][2] = dp[u][2] * (num1) % mod;
        dp[u][1] = dp[u][1] * (num1 + dp[v][0]) % mod;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef MYDEBUG
    freopen("../0in.txt", "r", stdin);
//    freopen("../0out.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    dfs(1);
    cout << (dp[1][0] + dp[1][1] - dp[1][2] - 1 + 2 * mod) % mod << endl;
    return 0;
}