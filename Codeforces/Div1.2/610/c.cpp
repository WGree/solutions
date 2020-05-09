//c.cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n, ti, p[2], cnt[2] = {};
        cin >> n >> ti >> p[0] >> p[1];
        vector<pii> a(n);
        for (int i = 0; i < n; ++i) {
            auto&[t, v] = a[i];
            cin >> v;
            ++cnt[v];
            v = p[v];
        }
        for (int i = 0; i < n; ++i) {
            auto&[t, v] = a[i];
            cin >> t;
        }
        a.emplace_back(ti + 1, 0);
        a.emplace_back(0, 0);
        sort(a.begin(), a.end(), [](auto a, auto b) { return a.first < b.first; });

        int ans = 0;
        ll cost = 0;
        for (int i = 0; i <= n; ++i) {
            auto[t, v] = a[i];
            cost += v;
            t = a[i + 1].first - 1;
            if (v == p[0]) --cnt[0];
            if (v == p[1]) --cnt[1];
            if (cost > t) continue;
            int tt = t - cost;
            int easy = min(tt / p[0], cnt[0]);
            tt -= easy * p[0];
            int hard = min(tt / p[1], cnt[1]);
            ans = max(ans, easy + hard + i);
        }

        cout << ans << endl;
    }
    return 0;
}