//B.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &i : a) cin >> i;
        sort(a.begin(), a.end());

        vector<int> ans;
        int l = 0, r = n - 1;
        while (l < r) {
            ans.emplace_back(a[l++]);
            ans.emplace_back(a[r--]);
        }
        if (l == r) ans.emplace_back(a[l]);
        for (int i = n - 1; i >= 0; --i) {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}