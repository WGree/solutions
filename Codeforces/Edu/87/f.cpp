//f.cpp
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main() {
using tri = tuple<int, int, int>;

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<tri> mon(n + 1);
        for (int i = 1, a, b; i <= n; ++i) {
            cin >> a >> b;
            mon[i] = {a, b, i};
        }
        sort(mon.begin() + 1, mon.end(), [](tri a, tri b) { return get<1>(a) < get<1>(b); });
        vector<vi> dp(n + 1, vi(k + 1, -1)), used(n + 1, vi(k + 1));
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                if (dp[i - 1][j] != -1) {
                    int tp = dp[i - 1][j] + (k - 1) * get<1>(mon[i]);
                    if (tp > dp[i][j]) {
                        dp[i][j] = tp;
                        used[i][j] = 0;
                    }
                }
                if (j > 0 && dp[i - 1][j - 1] != -1) {
                    int tp = dp[i - 1][j - 1] + (j - 1) * get<1>(mon[i]) + get<0>(mon[i]);
                    if (tp > dp[i][j]) {
                        dp[i][j] = tp;
                        used[i][j] = 1;
                    }
                }
            }
        }
        vector<int> use, nus;
        int x = n, y = k;
        while (x) {
            if (used[x][y]) {
                use.emplace_back(get<2>(mon[x]));
                --y;
            } else
                nus.emplace_back(get<2>(mon[x]));
            --x;
        }
        cout << k + (n - k) * 2 << endl;
        while (use.size() > 1) {
            cout << use.back() << ' ';
            use.pop_back();
        }
        for (int i : nus)
            cout << i << ' ' << -i << ' ';
        cout << use[0] << endl;
    }
    return 0;
}