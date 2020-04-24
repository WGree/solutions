//C.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int &i : a) cin >> i;
        int tt = 0;
        for (int i = n - 1, j; i >= 0; i = j) {
            j = i - 1;
            while (j >= 0 && a[j + 1] > a[j])
                --j;
            for (int k = j + 1; k <= i; ++k)
                b[tt++] = a[k];
        }
        if (is_sorted(b.begin(), b.end())) puts("Yes");
        else puts("No");
    }
    return 0;
}