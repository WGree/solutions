//C.cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (ll &i : a) cin >> i;
        ll sum = 0, la = a[0];
        for (int i = 1; i < n; ++i) {
            if (a[i] * la < 0) {
                sum += la;
                la = a[i];
            }
            la = max(la, a[i]);
        }
        sum += la;
        cout << sum << endl;
    }
    return 0;
}