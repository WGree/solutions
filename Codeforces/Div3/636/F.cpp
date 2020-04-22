//F.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    auto cmp = [](set<int> &a, set<int> &b) { return a.size() < b.size(); };

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> ans(n), tp;
        vector<set<int>> s, ss(n + 1);
        for (int i = 1, k, t; i < n; ++i) {
            cin >> k;
            for (int j = 0; j < k; ++j) {
                cin >> t;
                ss[i].emplace(t);
                if (k == 2) tp.emplace_back(t);
            }
        }
        sort(ss.begin(), ss.begin() + n, cmp);
        while (1) {
            s = ss;
            ans[0] = tp.back();
            tp.pop_back();
            for (int i = 1; i < n; ++i) {
                if (s[i].count(ans[0]))
                    s[i].erase(ans[0]);
            }
            sort(s.begin(), s.begin() + n, cmp);
            for (int i = 1; i < n; ++i) {
                ans[i] = *s[i].begin();
                for (int j = 1; j < n; ++j) {
                    if (s[j].count(ans[i]))
                        s[j].erase(ans[i]);
                }
                sort(s.begin(), s.begin() + n, cmp);
            }
            int ff = 1;
            for (int i = 1; i < n; ++i) {
                set<int> tt;
                int f = 0;
                tt.emplace(ans[i]);
                for (int j = i - 1; j >= 0; --j) {
                    tt.emplace(ans[j]);
                    if (find(ss.begin(), ss.end(), tt) != ss.end()) {
                        f = 1;
                        break;
                    }
                }
                if (!f) {
                    ff = 0;
                    break;
                }
            }
            if (ff) break;
        }
        for (int i = 0; i < n; ++i)
            cout << ans[i] << ' ';
        cout << endl;
    }
    return 0;
}