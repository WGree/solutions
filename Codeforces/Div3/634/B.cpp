//B.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n, a, b;
        cin >> n >> a >> b;
        for (int i = 0; i < n; ++i) {
            cout << char(i % b + 'a');
        }
        cout << endl;
    }
    return 0;
}