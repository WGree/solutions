//D.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(2 * k);
        for (int &i : a) cin >> i, --i;
        for (int i = 0; i < n / 2; ++i) {
            int s = a[i] + a[n - i - 1];
            int l = min(a[i], a[n - i - 1]);
            int r = max(a[i], a[n - i - 1]) + k;
            b[0] += 2;
            --b[l], --b[s];
            ++b[s + 1], ++b[r];
        }
        int ans = b[0];
        for (int i = 1; i < 2 * k; ++i) {
            b[i] += b[i - 1];
            ans = min(ans, b[i]);
        }
        cout << ans << endl;
    }
    return 0;
}