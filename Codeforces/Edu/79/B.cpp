//B.cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
 
int a[N];
 
int main() {
    int q;
    cin >> q;
    while (q--) {
        int n, k, ans = 0;
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        ll sum = 0, la = 0;
        for (int i = 1; i <= n; ++i) {
            if (la < a[i]) {
                sum += la;
                la = a[i];
                if (sum > k) break;
                ans = i;
            } else sum += a[i];
            if (sum > k) break;
        }
        if (k - sum >= la) ans = 0;
        cout << ans << endl;
    }
    return 0;
}