//a.cpp
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N = 2e5 + 5;

multiset<int> p[N];

int main() {
    int n;
    cin >> n;
    for (int i = 0, t, tp; i < n; ++i) {
        cin >> t;
        tp = t;
        for (int j = 2; j * j <= t; ++j) {
            if (tp % j == 0) {
                int k = 1;
                while (tp % j == 0) {
                    tp /= j;
                    k *= j;
                }
                p[j].emplace(k);
            }
        }
        if (tp != 1)
            p[tp].emplace(tp);
    }
    ull ans = 1;
    for (int i = 2; i < N; ++i) {
        if (p[i].size() == n - 1)
            ans *= *p[i].begin();
        if (p[i].size() == n)
            ans *= *(++p[i].begin());
    }
    cout << ans << endl;
    return 0;
}