//c2.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    const double pi = acos(-1);
    
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        double middle = pi / n;
        double a = (pi - middle) / 2;
        double x = sin(a) / sin(middle);
        double d1 = (round(n / 4.0)) * middle;
        double d2 = pi / 2 - d1;
        double ans = x * (sin(d1) + sin(d2)) / sin(pi / 4);
        printf("%.10lf\n", ans);
    }
    return 0;
}