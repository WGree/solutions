//b.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &i: a) cin >> i;
        sort(a.begin(), a.end());
        int ans = 0, la = -1;
        for (int i = 0; i < n; ++i) {
            if (i - la >= a[i]) {
                ++ans;
                la = i;
            }
        }
        if (n - 1 - la >= a[n - 1])
            ++ans;
        cout << ans << endl;
    }
    return 0;
}