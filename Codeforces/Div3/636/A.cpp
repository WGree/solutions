//A.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, c = 1;
        cin >> n;
        for (int i = 1; i < 31; ++i) {
            c |= 1 << i;
            if (n % c == 0) {
                cout << n / c << endl;
                break;
            }
        }
    }
    return 0;
}