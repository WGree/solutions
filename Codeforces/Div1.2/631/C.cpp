//C.cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int l[N];

int main() {
    int n, m, nn;
    ll sum = 0;
    cin >> n >> m;
    nn = n;
    vector<int> ans;
    for (int i = 0; i < m; ++i) {
        cin >> l[i];
        sum += l[i];
        if (l[i] > n) {
            cout << -1 << endl;
            return 0;
        }
        ans.emplace_back(n - l[i] + 1);
        --n;
    }
    if (sum < nn) {
        cout << -1 << endl;
        return 0;
    }
    if (ans.back() != 1) {
        ans.back() = 1;
        for (int i = m - 1; i > 0; --i) {
            if (ans[i] + l[i] < ans[i - 1])
                ans[i - 1] = ans[i] + l[i];
        }
    }
    for (int i : ans) cout << i << ' ';
    cout << endl;
    return 0;
}