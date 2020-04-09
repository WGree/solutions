//D.cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 3e6 + 5;

vector<int> ans[N];

int main() {
    int n, k;
    cin >> n >> k;
    vector<char> c(n);
    for (char &t : c) cin >> t;
    int cnt = 0, mx = 0;
    while (1) {
        int f = 0;
        for (int i = 0; i < n; ++i) {
            if (c[i] == 'R' && c[i + 1] == 'L') {
                ans[cnt].emplace_back(i + 1);
                swap(c[i], c[i + 1]);
                ++i; ++mx; f = 1;
            }
        }
        if (!f) break;
        else ++cnt;
    }

    if (mx < k || k < cnt) cout << -1 << endl;
    else {
        --cnt;
        for (int i = k - 1; i > 0; --i) {
            if (ans[cnt].empty()) --cnt;
            if (i == cnt) break;
            ans[i] = vector<int>{ans[cnt].back()};
            ans[cnt].pop_back();
        }
        for (int i = 0; i < k; ++i) {
            cout << ans[i].size() << ' ';
            for (int &j : ans[i]) 
                cout << j << ' ';
            cout << endl;
        }
    }
    return 0;
}