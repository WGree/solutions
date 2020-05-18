//c1.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    const double pi = acos(-1);
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        auto k = tan((n * 2 - 2) * pi / 4 / n);
        printf("%.10lf\n", k);
    }
    return 0;
}