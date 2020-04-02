//D.cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef MYDEBUG
    freopen("../0in.txt", "r", stdin);
//    freopen("../0out.txt", "w", stdout);
#endif

    int k;
    cin >> k;
    cout << "3 3" << endl;
    int c = 1 << (32 - __builtin_clz(k));
    cout << (c + k) << ' ' << k << " 0" << endl
         << c << ' ' << k << " 0" << endl
         << c << ' ' << (c + k) << ' ' << k << endl;
    return 0;
}