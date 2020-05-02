//a.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        cout << (1 << n / 2 + 1) - 2 << endl;
    }
    return 0;
}