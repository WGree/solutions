//Vestigium。cpp
#include <bits/stdc++.h>
using namespace std;

int mat[105][105];

int main() {
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        int n;
        cin >> n;

        int sum, cnt1, cnt2;
        sum = cnt1 = cnt2 = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> mat[i][j];
                if (i == j)
                    sum += mat[i][j];
            }
        }

        for (int i = 1; i <= n; ++i) {
            vector<int> has(105);
            for (int j = 1; j <= n; ++j) {
                if (has[mat[i][j]]) {
                    ++cnt1;
                    break;
                }
                has[mat[i][j]] = 1;
            }
        }

        for (int i = 1; i <= n; ++i) {
            vector<int> has(105);
            for (int j = 1; j <= n; ++j) {
                if (has[mat[j][i]]) {
                    ++cnt2;
                    break;
                }
                has[mat[j][i]] = 1;
            }
        }
        printf("Case #%d: %d %d %d\n", cas, sum, cnt1, cnt2);
    }
    return 0;
}