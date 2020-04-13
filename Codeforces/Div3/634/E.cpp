//E.cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int a[N], cnt[N][200];

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n, ans = 0;
        cin >> n;
        vector<vector<int>> pos(201);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            for (int j = 1; j <= 200; ++j) {
                cnt[i][j] = cnt[i - 1][j];
            }
            ++cnt[i][a[i]];
            pos[a[i]].emplace_back(i);
            ans = max(ans, cnt[i][a[i]]);
        }
        for (int i = 1; i <= 200; ++i) {
            if (pos[i].empty()) continue;
            int l = 0, r = pos[i].size() - 1;
            for (;l < pos[i].size() && l < r; ++l) {
                while (cnt[pos[i][l]][i] > cnt[n][i] - cnt[pos[i][r - 1]][i]) --r;
                if (l >= r) break;
                for (int j = 1; j <= 200; ++j) {
                    ans = max(ans, 2 * cnt[pos[i][l]][i] + cnt[pos[i][r] - 1][j] - cnt[pos[i][l]][j]);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}