//B.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n >> 1 & 1) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        for (int i = 1; i <= n / 2; ++i) {
            cout << i * 2 << ' ';
        }
        for (int i = 0, t = 1; i < n / 2; ++i) {
            cout << t << ' ';
            t += 2;
            if (i + 1 == n / 4)
                t += 2;
        }
        cout << endl;
    }
    return 0;
}