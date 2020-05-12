//c.cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
int to[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<string> s(n);
    for (auto &i : s) cin >> i;
    vector<vector<ll>> d(n, vector<ll>(m, INF64));
    queue<pii> que;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            bool good = false;
            for (auto &t2 : to) {
                int x = i + t2[0];
                int y = j + t2[1];
                if (0 <= x && x < n && 0 <= y && y < m && s[i][j] == s[x][y])
                    good = true;
            }
            if (good) {
                d[i][j] = 0;
                que.emplace(i, j);
            }
        }
    }
    while (!que.empty()) {
        auto[ux, uy] = que.front();
        que.pop();
        for (auto &t2 : to) {
            int x = ux + t2[0];
            int y = uy + t2[1];
            if (0 <= x && x < n && 0 <= y && y < m && d[x][y] == INF64) {
                d[x][y] = d[ux][uy] + 1;
                que.emplace(x, y);
            }
        }
    }
    int x, y;
    ll p;
    while (q--) {
        cin >> x >> y >> p;
        --x, --y;
        int t;
        if (p <= d[x][y]) t = 0;
        else t = (p - d[x][y]) & 1;
        cout << ((s[x][y] - '0') ^ t) << endl;
    }
    return 0;
}