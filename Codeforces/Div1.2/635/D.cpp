//D.cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;

ll ans;
int a[3][N], n[3];

void calc(int q, int w, int e) {
    for (int i = 0; i < n[q]; ++i) {
        auto p2 = lower_bound(a[w], a[w] + n[w], a[q][i]) - a[w];
        auto p3 = upper_bound(a[e], a[e] + n[e], a[q][i]) - a[e];
        if (p3 != 0) --p3;
        if (p2 == n[w]) --p2;
        ll x = a[q][i], y = a[w][p2], z = a[e][p3];
        ans = min(ans, (x - y) * (x - y) + (x - z) * (x - z) + (y - z) * (y - z));
        p2 = upper_bound(a[w], a[w] + n[w], a[q][i]) - a[w];
        p3 = lower_bound(a[e], a[e] + n[e], a[q][i]) - a[e];
        if (p2 != 0) --p2;
        if (p3 == n[e]) --p3;
        x = a[q][i], y = a[w][p2], z = a[e][p3];
        ans = min(ans, (x - y) * (x - y) + (x - z) * (x - z) + (y - z) * (y - z));
    }
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        cin >> n[0] >> n[1] >> n[2];
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < n[i]; ++j) {
                cin >> a[i][j];
            }
            sort(a[i], a[i] + n[i]);
        }
        ans = LLONG_MAX;
        calc(0,1,2);
        calc(1,0,2);
        calc(2,1,0);
        cout << ans << endl;
    }
    return 0;
}