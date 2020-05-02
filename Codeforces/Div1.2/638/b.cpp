//b.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int &i : a) cin >> i;
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
        if (a.size() > k) {
            cout << -1 << endl;
            continue;
        }
        while (a.size() < k)
            a.emplace_back(1);
        cout << k * n << endl;
        for (int i = 0; i < n; ++i) {
            for (int &j : a)
                cout << j << ' ';
        }
        cout << endl;
    }
    return 0;
}