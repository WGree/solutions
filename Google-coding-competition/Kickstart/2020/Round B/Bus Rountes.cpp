//Bus Rountes.cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        int n; ll d;
        cin >> n >> d;
        vector<ll> a(n);
        for (ll &i : a) cin >> i;
        ll las = d;
        for (int i = n - 1; i >= 0; --i) {
            las = las / a[i] * a[i];
        }
        ll ans = las;
        cout << "Case #" << cas << ": " << ans << endl;
    }
    return 0;
}