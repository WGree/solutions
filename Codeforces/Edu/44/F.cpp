//F.cpp
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int mod = 998244853;
const ull mod2 = 1610612741;
const int N = 2e5 + 5;

ull p[N], hah[N][26];

ull gethah(int id, int l, int r) {
    return (hah[r][id] - hah[l - 1][id] * p[r - l + 1] % mod2 + mod2) % mod2;
}

int main() {
    p[0] = 1;
    for (int i = 1; i < 2e5; ++i) {
        p[i] = p[i - 1] * mod % mod2;
    }
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    for (int i = 1; i <= s.length(); ++i) {
        hah[i][s[i - 1] - 'a'] = 1;
        for (int j = 0; j < 26; ++j) {
            (hah[i][j] += hah[i - 1][j] * p[1] % mod2) %= mod2;
        }
    }

    while (q--) {
        int x, y, len;
        cin >> x >> y >> len;

        vector<ull> xx(26), yy(26);
        for (int i = 0; i < 26; ++i) {
            xx[i] = gethah(i, x, x + len - 1);
            yy[i] = gethah(i, y, y + len - 1);
        }
        sort(xx.begin(), xx.end());
        sort(yy.begin(), yy.end());
        if (xx == yy) puts("YES");
        else puts("NO");
    }
    return 0;
}