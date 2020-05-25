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
        double middle = pi / n;
        double a = (pi - middle) / 2;
        printf("%.10lf\n", tan(a));
    }
    return 0;
}