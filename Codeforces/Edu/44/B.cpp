//B.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    char c;
    int n, m;
    cin >> n >> m;
    vector<int> cnt(m);
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> c;
            a[i][j] = c - '0';
            cnt[j] += a[i][j];
        }
    }

    int f = 0;
    for (int i = 0; i < n; ++i) {
        f = 1;
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == cnt[j]) {
                f = 0;
                break;
            }
        }
        if (f) break;
    }
    if (f) puts("YES");
    else puts("NO");
    return 0;
}