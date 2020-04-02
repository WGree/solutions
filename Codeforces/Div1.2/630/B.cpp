//B.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef MYDEBUG
    freopen("../0in.txt", "r", stdin);
//    freopen("../0out.txt", "w", stdout);
#endif

    int q;
    cin >> q;
    while (q--) {
        int n, t;
        cin >> n;
        vector<int> ans(n), tmp[1001];
        for (int i = 0; i < n; ++i) {
            cin >> t;
            for (int j = 2; j < 1001; ++j) {
                if (t % j == 0) {
                    tmp[j].emplace_back(i);
                    break;
                }
            }
        }
        int cnt = 0;
        for (auto &i : tmp) {
            if (!i.empty()) ++cnt;
            for (int j : i) ans[j] = cnt;
        }

        cout << cnt << endl;
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}