//D.cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;

int dp[N][N + 100];
pii to[N][N + 100];

int main() {
    int mp[10] = {0x77, 0x24, 0x5d, 0x6d, 0x2e, 0x6b, 0x7b, 0x25, 0x7f, 0x6f};

    int n, k;
    cin >> n >> k;
    vector<vector<pii>> a(n);
    string s;
    for (int i = 0, t; i < n; ++i) {
        cin >> s;
        t = 0;
        for (int j = 0; j < 7; ++j)
            t |= (s[j] - '0') << j;
        for (int j = 0; j < 10; ++j) {
            if ((t & mp[j]) == t) {
                bitset<8> aa(t ^ mp[j]);
                a[i].emplace_back(j, aa.count());
            }
        }
    }

    dp[0][0] = 1;
    for (int ii = 0; ii < n; ++ii) {
        int t = n - ii - 1;
        for (auto tp:a[t]) {
            for (int j = 0; j <= k; ++j) {
                if (!dp[ii][j])
                    continue;
                dp[ii + 1][j + tp.second] = 1;
                to[ii + 1][j + tp.second] = {j, tp.first};
            }
        }
    }

    if (!dp[n][k]) {
        cout << -1 << endl;
        return 0;
    }
    while (n) {
        cout << to[n][k].second;
        k = to[n][k].first;
        --n;
    }
    cout << endl;
    return 0;
}