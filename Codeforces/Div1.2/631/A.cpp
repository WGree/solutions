//A.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(205);
        for (int i = 0, t; i < n; ++i) {
            cin >> t;
            a[t] = 1;
        }
        int ans = 0;
        for (int i = 1; i <= 200; ++i) {
            a[i] += a[i - 1];
            if (i - a[i] == x) ans = i;
        }
        cout << ans << endl;
    }
    return 0;
}