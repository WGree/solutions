//a.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            a[i] += i;
            if (a[i] < 0) a[i] = (a[i] % n) + n;
            a[i] %= n;
        }
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
        if (a.size() != n) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}