//E.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n < 3) {
        cout << -1 << endl;
        return 0;
    }
    vector<vector<int>> ans(n + 1, vector<int> (n + 1));
    int cnt = n * n;
    ans[2][3] = cnt--; ans[1][1] = cnt--; ans[2][1] = cnt--;
    ans[3][1] = cnt--; ans[1][2] = cnt--; ans[2][2] = cnt--;
    ans[3][2] = cnt--; ans[3][3] = cnt--; ans[1][3] = cnt--;
    for (int i = 4; i <= n; ++i) {
        if (i % 2 == 0) {
            for (int j = 1; j <= i; ++j) ans[j][i] = cnt--;
            for (int j = i - 1; j > 0; --j) ans[i][j] = cnt--;
        } else {
            for (int j = 1; j <= i; ++j) ans[i][j] = cnt--;
            for (int j = i - 1; j > 0; --j) ans[j][i] = cnt--;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            cout << ans[i][j] << ' ';
        cout << endl;
    }
    return 0;
}