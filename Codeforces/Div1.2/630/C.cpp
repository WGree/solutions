//C.cpp
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
    string s;
    while (q--) {
        int n, k;
        cin >> n >> k >> s;
        int ans = 0;
        vector<int> v(n);
        for (int i = 0; i < k; ++i) {
            vector<int> cnt(26);
            int tmp = 0, num = 0;
            for (int j = i; j < n; j += k) {
                if (!v[j]) {
                    v[j] = 1;
                    ++cnt[s[j] - 'a'];
                    ++num;
                }
                if (!v[n - j - 1]) {
                    v[n - j - 1] = 1;
                    ++cnt[s[n - j - 1] - 'a'];
                    ++num;
                }
            }
            for (int j = 0; j < 26; ++j) {
                tmp = max(tmp, cnt[j]);
            }
            tmp = num - tmp;
            ans += tmp;
        }
        cout << ans << endl;
    }
    return 0;
}