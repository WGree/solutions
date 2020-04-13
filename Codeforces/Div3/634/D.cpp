//D.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        string s[9];
        for (auto &i : s) cin >> i;
        s[0][0] = s[1][1];
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                s[i * 3 + j][j * 3 + i] = s[i * 3][j * 3];
            }
        }
        for (auto &i : s) cout << i << endl;
    }
    return 0;
}