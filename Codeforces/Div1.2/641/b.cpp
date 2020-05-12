//b.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;
        bool fl = false;
        vector<int> a(n);
        for (int &i : a) {
            cin >> i;
            if (i < k) i = -1;
            else if (i > k) i = 1;
            else {
                i = 1;
                fl = true;
            }
        }
        if (!fl) {
            cout << "no" << endl;
            continue;
        }
        if (n == 1) {
            cout << "yes" << endl;
            continue;
        }

        fl = false;
        for (int i = 0; i < n - 1 && !fl; ++i) {
            if (a[i] + a[i + 1] > 0)
                fl = true;
            if (i < n - 2 && a[i] + a[i + 1] + a[i + 2] > 0)
                fl = true;
        }
        if (fl) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}