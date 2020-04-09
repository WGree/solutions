//A.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        if (n * m & 1) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j)
                    cout << "BW"[(i + j) & 1];
                cout << endl;
            }
        } else {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j)
                    cout << "WB"[(i + j) & 1 | (i==0&&j==0)];
                cout << endl;
            }
        }
    }
    return 0;
}