//b.cpp
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vi a(n);
        for (int &i : a) cin >> i;
        sort(a.begin(), a.end());
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            if (i + 1 >= a[i])
                ans = i + 2;
        }
        cout << ans << endl;
    }
    return 0;
}