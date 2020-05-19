//Stable Wall.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        int e[27][27] = {}, ind[26] = {}, has[26] = {};
        int n, m, cnt = 0;
        cin >> n >> m;
        vector<string> w(n + 1);
        for (int i = 0; i < n; ++i) {
            cin >> w[i];
            for (int j = 0; j < m; ++j) {
                if (!has[w[i][j] - 'A']) {
                    has[w[i][j] - 'A'] = 1;
                    ++cnt;
                }
            }
        }
        w[n] = string(m, 26 + 'A');
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < m; ++j) {
                int aa = w[i + 1][j] - 'A';
                int bb = w[i][j] - 'A';
                if (aa == bb) continue;
                if (!e[aa][bb]) ++ind[bb];
                e[aa][bb] = 1;
            }
        }
        queue<int> q, s;
        q.emplace(26);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            s.emplace(u);
            for (int i = 0; i < 26; ++i) {
                if (e[u][i]) {
                    --ind[i];
                    if (!ind[i])
                        q.emplace(i);
                }
            }
        }
        s.pop();
        string ans;
        if (s.size() < cnt)
            ans = "-1";
        else {
            while (!s.empty()) {
                ans.push_back(s.front() + 'A');
                s.pop();
            }
        }
        printf("Case #%d: %s\n", cas, ans.c_str());
    }
    return 0;
}