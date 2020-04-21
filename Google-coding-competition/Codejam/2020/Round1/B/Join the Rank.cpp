//Join the Rank.cpp
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        int r, c, f = 0;
        cin >> r >> c;

        string s;
        for (int i = 0; i < c; ++i) {
            for (int j = 0; j < r; ++j) {
                s.push_back(j);
            }
        }
        vector<pii> ans;
        while (1) {
            vector<char> p;
            int i, a, b = -1;
            p.emplace_back(s[0]);
            for (i = 1; i < r * c; ++i) {
                if (s[i] != s[i - 1]) {
                    if (p.size() == 2) {
                        a = i;
                        break;
                    }
                    p.emplace_back(s[i]);
                }
            }
            for (; i < r * c; ++i) {
                if (s[i - 1] == p[0] && s[i] == p[1]) {
                    b = i;
                    break;
                }
            }
            if (b == -1) break;
            ans.emplace_back(a, b);
            s = s.substr(a, b - a) + s.substr(0, a) + s.substr(b);
        }
        if (!is_sorted(s.begin(), s.end())) {
            ans.emplace_back(c - 1, r * c - 1);
        }
        printf("Case #%d: %d\n", cas, ans.size());
        for (auto &i : ans)
            printf("%d %d\n", i.first, i.second - i.first);
    }
    return 0;
}