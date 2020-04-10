//C.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, l;
    cin >> n >> k >> l;
    vector<int> a(n * k);
    for (int &i : a) cin >> i;
    sort(a.begin(), a.end());
    int ptr = upper_bound(a.begin(), a.end(), a[0] + l) - a.begin() - 1;
    if (ptr + 1 < n) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = 0;
    vector<int> tmp1, tmp2;
    for (int i = 0; i <= ptr; ++i) {
        tmp1.emplace_back(a[i]);
    }
    for (int i = ptr + 1; i < n * k; ++i) {
        tmp2.emplace_back(a[i]);
    }
    while (n--) {
        vector<int> tt;
        while (tt.size() + 1 < k && !tmp2.empty()) {
            tt.emplace_back(tmp2.back());
            tmp2.pop_back();
        }
        while (tt.size() < k) {
            tt.emplace_back(tmp1.back());
            tmp1.pop_back();
        }
        ans += tt.back();
    }
    cout << ans << endl;
    return 0;
}