//C.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        map<int, int> mp;
        for (int i = 0, t; i < n; ++i) {
            cin >> t;
            ++mp[t];
        }
        vector<pii> cnt;
        for (auto &i : mp) {
            cnt.emplace_back(i.second, i.first);
        }
        sort(cnt.begin(), cnt.end());
        int ans = 0;
        if (cnt.back().first - 1 >= cnt.size())
            ans = cnt.size();
        for (int i = cnt.size() - 1; i > 0 && !ans; --i) {
            if (cnt.back().first >= i ) {
                ans = i;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}