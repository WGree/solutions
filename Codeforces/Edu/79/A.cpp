//A.cpp
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int q;
    cin >> q;
    while (q--) {
        int a[3];
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a + 3);
        if (a[0] + a[1] < a[2] - 1) puts("No");
        else puts("Yes");
    }
    return 0;
}