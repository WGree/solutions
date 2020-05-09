//e.cpp
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 1e5 + 5;

struct tri {
    int a[3];
} cc[N];

map<pii, int> mp;
set<int> st[N];

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            st[i].clear();
        mp.clear();
        for (int i = 1; i <= n - 2; ++i) {
            auto&[a] = cc[i];
            cin >> a[0] >> a[1] >> a[2];
            sort(a, a + 3);
            for (int j = 0; j < 3; ++j)
                st[a[j]].emplace(i);
            ++mp[{a[0], a[1]}];
            ++mp[{a[0], a[2]}];
            ++mp[{a[1], a[2]}];
        }
        vector<vi> g(n + 1);
        for (auto &i : mp) {
            if (i.second & 1) {
                const pii &t = i.first;
                g[t.first].emplace_back(t.second);
                g[t.second].emplace_back(t.first);
            }
        }
        vector<int> vis(n + 1);
        function<void(int, int)> dfs = [&](int s, int fa) {
            cout << s << ' ';
            vis[s] = 1;
            for (int u : g[s]) {
                if (!vis[u]) {
                    dfs(u, s);
                }
            }
        };
        dfs(1, 0);
        cout << endl;

        queue<int> Q;
        for (int i = 1; i <= n; ++i) {
            if (st[i].size() == 1) {
                Q.emplace(i);
            }
        }
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            if (st[u].empty())break;
            int tt = *st[u].begin();
            cout << tt << ' ';
            auto&[a]= cc[tt];
            for (int i : a) {
                st[i].erase(tt);
                if (st[i].size() == 1)
                    Q.emplace(i);
            }
        }
        cout << endl;
    }
    return 0;
}