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
        double a = pi / n;
        double len = 0.5 / sin(a / 2);
        double r1 = round(n / 4.0) * a, r2 = pi / 2 - r1;
        r1 = len * sin(r1)/ sin(pi / 4);
        r2 = len * sin(r2)/ sin(pi / 4);
        printf("%.10lf\n", r1 + r2);
    }
    return 0;
}