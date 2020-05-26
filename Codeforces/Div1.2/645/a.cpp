//a.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        a *= b;
        if (a & 1) cout << a / 2 + 1 << endl;
        else cout << a / 2 << endl;
    }
    return 0;
}